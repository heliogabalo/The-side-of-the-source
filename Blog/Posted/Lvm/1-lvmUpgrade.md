Actualizar el sistema, no es los mismo que poner al día la versión del sitema operativo. Algunos -como el que subscribe, confunde estos conceptos, por que en inglés son utilizadas dos palabras, muy similares: _update_ y _upgrade_.

_update_, es algo así como _poner a fecha_.
_upgrade_, sería _poner a grado_. 

En castellano utilizamos habitualmente, la misma palabra para referirnos a _Actualizar_, aunque son conceptos distintos.

Con esta entrada de _blog_, recogemos una técnica mediante el uso del gestor _LVM_, para llevar a cabo este tipo de operaciones de mantenimiento del sistema.
El artículo original, puede leerse en inglés en <http://fedoramagazine.org> por __Stuart D Gathman__.

La técnica consiste en preparar un _medio_ o dispositibo de bloque, donde posteriormente será "actualizado" el sistema. En _territoriolinux.net_ no haremos distinción, entre una u otra acción, puesto que no afecta al proceso que nos concierne.

Es recomendable, familiarizarse con los conceptos más generales del gestor LVM, puesto que podrían perderse datos o incluso, forzarnos a reinstalar el sistema operativo. 

En un entorno de desarrollo -referencia al laboratorio <territoriolinux.net>, lo primero será actualizar -a fecha, el sistema. Por lo que en nuestro entorno de producción, no es la opción más recomendable, puesto que nos hace perder un _valioso tiempo_.

		$ sudo dnf update
		$ sudo systemctl reboot
		
A continuación se comprueba através del _gestor_, el sistema de archivo raíz. Es una buena costumbre denominar al _FS root -o volúmen lógico LV_ con el nombre del SO. En caso de Fedora como las instalaciones fueron hechas mediante el gestor LVM, encontraríamos algo así:

		$ df /
		Filesystem 1K-blocks Used Available Use% Mounted on /dev/mapper/vg_sdg-f26 20511312 14879816 4566536 77% /
		
		$ sudo lvs
		LV        VG           Attr LSize Pool Origin Data% Meta% Move Log Cpy%Sync Convert
		f22       vg_sdg -wi-ao---- 15.00g
		f24_64    vg_sdg -wi-ao---- 20.00g
		f26       vg_sdg -wi-ao---- 20.00g
		home      vg_sdg -wi-ao---- 100.00g
		mockcache vg_sdg -wi-ao---- 10.00g
		swap      vg_sdg -wi-ao---- 4.00g
		test      vg_sdg -wi-a----- 1.00g
		vg_vm     vg_sdg -wi-ao---- 20.00g
		
Al utilizar los valores por defecto, durante la instalación de Fedora, podría encontrarse el sistema de ficheros raíz, montodo bajo el nombre `root`. El nombre del _grupo de volúmenes (VG)_, podría ser distinto. Resaltar, el tamaño del volumen raíz. En el ejemplo, el FS raíz es nombrado __f26__, con un tamaño de 20G.
		
Con esto estamos metiendo en el "pool" o piscina del gestor(PV), todo el espacio no utilizado en el `home`. Después podrá utilizarse para crear un nuevo/s LV's. PV, significa Phisical Volume, volúmen físico.
		
1. `/home`, en us própio _LV_, con mucho espadio libre.

Es posible cerrar la interfase gráfica de usuario(GUI), cambiar a la cónsola de texto e, identificarnos como `root`. Desmontar el `/home` y, redimensionarlo con `lvreduce -r` para conseguir maximizar el espacio libre que no está siendo utilizado. 

__nota__: Entiendase esto, como una alternativa/observación, para aquellos que anden escasos de espacio disponible. Lo mismo podría hacerse de variopintas formas distintas.
`Gparted`, es otra opción para manipular particiones, etc, con la garantía de no estar nunca trabajando sobre FS's montados -arrancar con un live-CD, para conseguir el efecto deseado! 

2. La mayor parte del espacio disponible, asignado mediante el LVM, en el LV raíz.

En este caso es mejor arrancar directamente desde un _live-CD_. _Gparted_ es una buena opción; cabría considerar mover el `/home` a una partición independiente, aunque esto último queda fuera de ámbito del artículo.

3. Podría presentarse un escenario, donde todos los FS están _llenos_, pero hay _LV's_ que no están siendo utilizados. Es buena idea borrar los LV's en desuso, liberando el espacio en el grupo de volúmenes
		
### Creando el backup ###

Primero, creamos el LV para la actualización del sistema. Habrá que comprobar dos veces, que el nombre del _VG_ coincide con el que asignamos previamente a nuestro sistema. En este ejemplo `vg_sdg`.

		$ sudo lvcreate -L20G -n f28 vg_sdg
		Logical volume "f28" created.

A continuación, se definirá un _punto de captura (snaphshot)_, del sistema de archivos en uso. En éste ejemplo su nombre es `f26_s`.

		$ sync
		$ sudo lvcreate -s -L1G -n f26_s vg_sdg/f26
		Using default stripesize 64.00 KiB.
		Logical volume "f26_s" created.

__nota__: `sync`, sin argumentos ni archivos especificados. Esto significa que se llevará a cabo una sincronización del FS sobre el que nos encontramos; el _root_ en este caso.
Ver artículo [Qemu](URL), para una descripción más detallada sobre _capturas_.

Seguidamente podrá ser copiada la captura al nuevo LV. Debería comprovarse otra vez, que la destinación es la adecuada, en el momento de sustituir el nombre del VG. De otra forma, correríamos el riesgo de borrar __irremediablemente__ los datos. También cerciorarse de que la copia procede de la captura del FS raíz  y _no, del raíz en vivo_.

		$ sudo dd if=/dev/vg_sdg/f26_s of=/dev/vg_sdg/f28 bs=256k
		81920+0 records in
		81920+0 records out
		21474836480 bytes (21 GB, 20 GiB) copied, 149.179 s, 144 MB/s

Asignar un UUID único, a la copia del nuevo FS. Aunque no es estríctamente necesario, si recomendable puesto que evitará futuras confusiones. 

		$ sudo e2fsck -f /dev/vg_sdg/f28
		$ sudo tune2fs -U random /dev/vg_sdg/f28

El primer comando es utilizado para comprovar si un FS -ext2, ext3, ext4, fué _apagado_ de forma correcta, o sin errores. Ver `man e2sfck`. La opción ` -f ` fuerza la commprovación, incluso si el FS parece limpio.

El segundo comando permite ajustar varios parámetros, sobre un FS del tipo ext2, ext3, ext4. La opción `-U random` establece un UUID aleatorio.

Una vez hecho esto, podrá retirarse el volumen _captura_, el cuál ya no es necesario:

		$ sudo lvremove vg_sdg/f26_s
		Do you really want to remove active logical volume vg_sdg/f26_s? [y/n]: y
		Logical volume "f26_s" successfully removed

También podría ser creada una captura del `/home`, de haber sido montado de forma separada. Algunas veces, nuevas versiones de programas, harán cambios incompatibles con versiones anteriores del Sistema operativo.
De ser necesario, editar el archivo `/etc/fstab`, del  _previo_ FS raíz, para montar la captura en el `/home`. Recordar, que __desaparecerá la captura una vez llena__. Sería conveniente realizar una copia de seguridad del `/home`, como medida preventiva ante eventuales desastres! 


### Configuración de nuevo raíz ###

Primero, es montado el nuevo LV, creando una copia de respaldo después, de la configuración del _GRUB_.

		$ sudo mkdir /mnt/f28
		$ sudo mount /dev/vg_sdg/f28 /mnt/f28
		$ sudo mkdir /mnt/f28/f26
		$ cd /boot/grub2
		$ sudo cp -p grub.cfg grub.cfg.old
		
_Clic en el editor_, para abrir el archivo de configuración `grub.conf`. A menos que ya contenga la siguiente línea, deberíamos añadirla:

		menuentry 'Old boot menu' {
				    configfile /grub2/grub.cfg.old
		}

La línea que hace referencia a la imagen del kernel, debería cambiarse igualmente. Atención al argumento que describre el dispositivo raíz:

		linux16 /vmlinuz-4.16.11-100.fc26.x86_64 <strong>root=/dev/mapper/vg_sdg-f26 ro rd.lvm.lv=vg_sdg/f26 rd.lvm.lv=vg_sdg/swap</strong> rhgb quiet LANG=en_US.UTF-8	

Una vez cambiado, debería parecerse a lo siguiente. Recordar el nombre del _VG_ si fue definido de otro modo.

		linux16 /vmlinuz-4.16.11-100.fc26.x86_64 <strong>root=/dev/mapper/vg_sdg-f28 ro rd.lvm.lv=vg_sdg/f28 rd.lvm.lv=vg_sdg/swap</strong> rhgb quiet LANG=en_US.UTF-8

En `/etc/default/grub`, hay que tocar la variable `GRUB_CMDLINE_LINUX` de la siguiente manera:

		GRUB_CMDLINE_LINUX="rd.lvm.lv=vg_sdg/f28 rd.lvm.lv=vg_sdg/swap rhgb quiet"
		
> __Apunte__: hay dos referencias; una al FS raíz y, otra al FS de intercambio -la _swap_. Habría que echar un ojo a `fdisk` si no recordamos como fue hecha la instalación del sistema. En cualquier caso, es buena idea añadir la referencia a la `swap`, que por otro lado, no es necesario duplicar, ojo!

Al archivo `/etc/fstab` hay que cambiarle la definición del FS raíz, para que al arrancar el sistema, cargue el nuevo FS.

Cambiar:
		/dev/mapper/vg_sdg-f26 / ext4 defaults 1 1
Por:
		/dev/mapper/vg_sdg-f28 / ext4 defaults 1 1
Y añadir, 
		/dev/mapper/vg_sdg-f26 /f26 ext4 ro,nodev,noexec 0 0
para convertir al FS en un dispositivo de sólo lectura, en _futuras referencias_.

Si el sistema de ficheros raíz, es montado através de _UUID_, será necesario cambiar esto:

		$ sudo e2label /dev/vg_sdg/f28 F28
		
En caso de utilizar _UUID_ habrá que volver a cambiar la línea que lee el punto de montaje del FS raíz, debe ser similar a:

		LABEL=F28 / ext4 defaults 1 1
		
> Recordar, que dependiendo de donde hayamos montado el LV, `/etc/fstab` estará situado en dicho directorio; `/mnt/f28/etc/fstab` en el ejemplo de esta entrada de blog.

Tan sólo queda reiniciar el sistema y "Actualizar" a gusto del consumidor!

Saludos,


		
		

