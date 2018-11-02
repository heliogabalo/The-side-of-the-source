## LVM - copias de seguridad

Desde hace algunas semanas, venía pensando en escribir una entrada sobre el
particionado de disco, pero la idea solapaba a otra: __las copias de seguridad o _backups_.__

Más que tratar de explicar qué son las _LVM's_ o como configurarlas,
voy a dejar documentado como llevar a cabo una copia de seguridad,
sobre un sistema con una _LVM_ instalada.

Al final del artículo, podrán encontrarse varias referencia a páginas
sobre las que se habla _extensamente_ acerca de la configuración de
un _Gestor de Volúmenes Lógicos o LVM_.

En particular, quiero resaltar uno que me ha parecido especialmente
_esclarecedor_: [un pinguino en mi servidor][1], por estar escrito
entéramente en castellano, y por los evocadores dibujos a mano alzada!

De esta forma, cuando se instaló el sistema operativo, en lugar de instalar
el `/boot` en una partición -_LV_ en éste caso, distinta al `/root`, se optó
por incluirlo en este último.

#### El proceso

El escenario es el siguiente:
- __/dev/sda:__ el dispositivo contiene la _LVM_ al cuál se le ha asignado 	el
espacio total del disco.
- __/dev/sdb:__ se trata de un disco externo tipo _USB_, donde inicialmente se
creo otro gestor _LV_.

Mediante los siguiente comandos, se comprueba la situación actual de los
dispositivos(siempre como _root_).

		# pvdisplay

La salida de éste comando debe mostrar el volumen/es, físico conectado a la _LVM_.
Así, dependiendo de la forma en que haya sido instalado el sistema operativo,
podrá encontrarse algo como una partición primaria o una partición lógica.
Solo recordar, que las particiones lógicas empiezan a numerarse desde el _5_.
- `/dev/sda1` -- primaria.
- `/dev/sda5` -- lógica, precedida de una partición extendidad, ocupando el espacio
de una partición primaria.

Desde el punto de vista de una _LVM_ esta información no tiene demasiada
relevancia, pero resulta útil, a la hora de interpretar que tipo de dispositivo,
ha sido acoplado al recurso.

		#vgdisplay

El grupo de volúmenes, va a justificar que fijemos la atención en el nombre
del dispositivo, es decir, `VG Name:  _mi_VG_` debe hacer referencia al
nombre del _LVM_ con el que se vaya a trabajar.
Por ejemplo, si trabajamos con dos discos duros, quizá hayamos acoplado ambos
al mismo dispositivo(_LVM_), en tal caso únicamente aparecerá un recurso.
Si por el contrario, cuando hicimos la instalación, no tuvimos en cuenta el
_disco externo(USB)_, y dedicimos crear un nuevo dispositivo, con éste
comando deberiamos ver ambos _LVM's_; uno para el disco interno
`VG Name:  _mi_VG_`, y otro para el disco externo `VG Name:  _mediaDisc_`.

		#lvdisplay
Igualmente puede utilizarse el comando `lvs`, que no es más que un formato
abreviado con la misma función; mostrar los volúmenes lógicos que contiene el
recurso.

Ahora, deberíamos cruzar la información de las anteriores funciones, con el
comando `fdisk -l`, el cuál devolverá una lista de todas las particiones,
tamaños, tipo, sector, etc.

Resulta interesante ver, como `fdisk` está llamando a la partición que
contiene el _LVM_:

		Disposit.  Inicio  Comienzo      Final   Sectores Tamaño Id Tipo
		/dev/sda1		...			...						...			...				..	 8e	Linux LVM

...y cuando hace el listado de los distintos _volúmenes lógicos_, en lugar
de llamarlo `/dev/sda5` como lo haría para una partición extendida con las
subsiguientes _lógicas_ colgadas de ésta; lo hace de la siguiente manera:

		...
		Disco /dev/mapper/multimedia-home--extra:	1G ... bytes, ... sectores
		...


En realidad, `/dev/mi_VG/root` es un enlace a `/dev/mapper/mi_VG-root`, por
lo que ambas notaciones pueden usarse sin discriminación.
He querido citar la línea referida al dispositivo _USB_ por que son los
dispositivos con los que se trabajará y, por que aparece un guión que parece
salido de la nada y resulta curioso comentarlo.

El _PV_ del _USB_: `/dev/sdb1`.
El _VG_ del disco externo se declaró: `multimedia`.
El _LV_: `home-extra`.

Hasta aquí, lo único que se ha hecho es reunir información. Con esto quiero decir,
que la cantidad de escenarios diferentes, donde podamos encontrarnos en la
necesidad de crear una copia de seguridad o _backup_ es como poco _numerosa_.

Así que después de haber hecho las comprobaciones oportunas, podría resumir el
proceso de la siguiente manera:

1. Crear el _LV_. Es donde guardaremos la copia o respaldo de la partición `/root`.
Para lograrlo, se deberá seguir el esquema de montaje de cualquier _LVM_, primero
el _PV_, a continuación el _VG_ y, por último el dispositivo con el que se debe
trabajar, el _LV_.  
Como además será necesario montar la partición, primero habrá que darle formato
con un sistema de fichero como `EXT3`, crear un punto de montaje y por fin,
montar el dispositivo.  
Las siguientes acciones construirán el _LV_ necesario, pero antes, hay que
particionar el disco. Se puede usar `fdisc`. Siguiendo las indicaciones de la
aplicacion, deberíamos terminar con una partición tipo `8e` que es el _LVM_.  
Sin embargo, personalmente prefiero _Gparted_, ya que al cargar este pequeño
sistema operativo dede un _liveCD_, además de contar con las herramientas
graficas de particionado, podremos disponer de las aplicaciones necesarias
para la gestión de _LVM_ -tambien _RAID_`mdadm`, con la seguridad de no estar
trabajando sobre dispositivos montados.

		# pvcreate /dev/sdb1
		# vgextend server1 /dev/sdb1
		# lvcreate --name backups --size 30G server1
		# mkfs.ext3 /dev/mapper/server1-backups
		# mkdir /backups
		# mount /dev/mapper/server1-backups /backups

>En este escenario, es creado un dispositivo desde el segundo disco (/dev/sdb1
>	--primera partición primaria del segundo disco) y acoplado el
>dispositivo al único _LVM_ en el sistema!!.  
> Con el comando `lvcreate` `-s` para snapshot `--size` indica tamaño.


2. A continuación, para evitar tener que montar el volumen cada vez
que reinicia el sistema, se añadirá una entrada al final del archivo
`/etc/fstab`.  
		# vi /etc/fstab
		[...]
		/dev/mapper/server1-backups /backups               ext3    defaults,errors=remount-ro 0       1  
Nuevamente con el comando `pvdisplay` se comprueba que el dispositivo ha
sido acoplado al _LVM_, debiendo aparecer ambos volúmenes físicos(disco 1 y disco 2).  
Igualmente se vuelve a comprobar con `vgdisplay` que el tamaño del grupo de
volúmenes ha cambiado, esto es por ha sido añadido una nueva partición _PV_ de
`60G`, para tener espacio suficiente donde almacenar las capturas.  
		antes:		 VG Size               9.76 GB  
		después: 	 VG Size               69.75 GB  
Con `lvdisplay` podrán verse los distintos _LV_, en particular, el que
recientemente ha sido añadido: `/dev/server1/backups` y el tamaño con el
que se definió.  
		...  
		LV Size                30.00 GB  
		...  
Ahora pude crearse la captura _snapshot_, a la que llamaremos `rootsnapshot`.
		# lvcreate -L10 -s -n rootsnapshot /dev/server1/root  
La salida por pantalla con `lvdisplay`  

		--- Logical volume ---
		LV Name                /dev/server1/rootsnapshot
		...
		# open                 1
		LV Size                9.30 GB
		Current LE             2382
		COW-table size         10.00 GB
		...  
Seguidamente creamos un directorio y montamos la captura.  
		# mkdir -p /mnt/server1/rootsnapshot  
		# mount /dev/server1/rootsnapshot /mnt/server1/rootsnapshot  

3. Después de haber montado la imagen, es conveniente ver el contenido de la
misma, para ello:

		$ ls -l /mnt/server1/rootsnapshot/

Si todo fué bién, debería poder verse el contenido exacto del directorio `/root`,
así que la captura tuvo éxito.
Es ahora cuando creamos la copia o backup. Puede utilizarse `tar` para comprimir
la imagen en un archivo o, la aplicación `dd` para hacer una copia exacta de la
captura.

		# tar -pczf /backups/root.tar.gz /mnt/server1/rootsnapshot

		# dd if=/dev/server1/rootsnapshot of=/backups/root.dd
		19513344+0 records in
		19513344+0 records out
		9990832128 bytes (10 GB) copied, 320.059 seconds, 31.2 MB/s

---

De esta forma preparamos a nuestro sistema para _casi_ cualquier contingencia.

		# ls -l /backups/
		total 9947076
		drwx------ 2 root root      16384 2007-04-10 21:04 lost+found
		-rw-r--r-- 1 root root 9990832128 2007-04-10 21:28 root.dd
		-rw-r--r-- 1 root root  184994590 2007-04-10 21:18 root.tar.gz

En este último paso desmontamos y borramos la captura, para no ocupar espacio
innecesario en el sistema:

		# umount /mnt/server1/rootsnapshot
		# lvremove /dev/server1/rootsnapshot

---





[1]:https://blog.inittab.org/administracion-sistemas/lvm-para-torpes-i/

https://www.howtoforge.com/linux_lvm_snapshots_p3
grate -l myLV hd1 hd2
