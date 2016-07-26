1. [PROCESO DE INSTALACION DE UNA IMAGEN](#i1) 
    1. Crear imagen  
    2. [Convertir imagen](#i2)

2. TRABAJAR CON UNA COPIA DE IMAGEN
    1. Backing-files/overlays
    2. Snapshots 
3. [CON O SIN CONEXION A INTERNET](#i3)
    1. Modo usuario
    2. Modo Tap
4. EL LOOPBACK
    1. MONTAR UN LOOPBACK PARA COMUNICARNOS CON LA VM SIN CONEXION
    2. LOOPBACK PARA UNA IMGEN (USANDO MODULOS EN EL KERNEL)  
      - Lanzar la VM apuntando al servidor NBD
6. EXPERIMENTAL
7. AGRADECIMIENTOS


---
## 1. <a name="i1">PROCESO DE INSTALACION DE UNA IMAGEN</a>  

#### Crear imagen

Bien sea porque tenemos el disco original (en este caso un SO windows)  
o bien porque lo hayamos descargado, deberemos antes CREAR una imagen GUEST  
con la que  QEMU, pueda trabajar.
  
- Para esto primero creamos la imagen. Una "caja" vacía. 
   
  ~~~
 qemu-img create -f qcow2 mi_imagen.img 1G
  ~~~

 Aquí el flag "-f" indica el tipo de formato con el que será creada nuestra imagen (aún vacia).  
 También indicamos el archivo imagen y el tamaño en Gigabytes.

- Instalación de SUPUESTO OS en la imágen previamente creada:  
  ```bash  
 qemu -m 256 -hda mi_imagen.img -cdrom winxpsp2.iso -boot d  
  ```
Este comando anterior es un poco confuso.
- Habrá que sustituir "qemu" con el comando apropiado, en relación a la arquitectura  
del sistema operativo GUEST con el que se vaya a trabajar. En este caso sería:  
_qemu-system-i386_
- Nuevamente el flag -m indica la memoria RAM para el SUPUESTO SO.
- La siguiente opción -hda indica el archivo imagen donde vamos a instalar la imagen  
del SO.
- Sigue la opción -cdrom. Parece indicar el dispositivo físico un 'CD', pero todo  
apunta a que se trata de una denominación para diferenciarlo de la partición GUEST  
que acabamos de crear. Es decir, que utilizaremos el mismo flag '-cdrom' para tratar  
con una imagen descargada en el disco duro, o una imagen que previamente hayamos  
'quemado' en un 'CD'.  
La diferencia es que para utilizar un 'CD' a la hora de hacer la instalación en  
nuestra 'caja vacía' habrá que indicar la ruta hacia el dispositivo ejem. /dev/cdrom  
La opción -boot d indica como 'cadena' la letra que será usada en el arranque del sistema.  
Es exactamente igual a como interpreta la BIOS el 'orden' de arranque de sistema de  
nuestro HOST.  
    - 'a' y 'b' para la floppy
    - 'c' para el disco duro
    - 'd' para el CD-ROM
    - 'n-p' arranque desde RED. Opcion muy interesente para un GUEST. Investigar!!!  
Desde Linux, la cadena que representa el dispositivo de arranque, está muy claro,  
(pues nosotros no usamos letras para esto). Así que 'c' claramente representa al  
disco duro y 'd' a un CD-ROM.  
Desde una perspectiva Windows, habrá que asegurarse. Pués windows utiliza letras para  
denominar los dispositivos de almacenamiento.

#### <a name="i2">Convertir imagen</a> 

Por qué convertir imágenes antes de instalarlas:  

  ~~~
  # qemu-img convert -f vhd -O qcow2 source.vhd destination.qcow2  
  ~~~
> Es posible que la instrucción no funcione correctamente debido a algún  
> cambio en la version utilizada con _qemu_. Este otro comando debería funcionar.  

  ~~~
  qemu-img convert -O qcow2 filename file_output  (autodetectada??)  
  ~~~


Qemu tiene el conversor de imagenes mas versatil, en relación a otros emuladores.  
Esto lo convierte en una herramienta indispensable a la hora de trabajar con VMs.  
Así como otros emuladores, presentan limitaciones a la hora de trabajar con imagenes  
específicas, qemu es capaz de interpretar una gran variedad de éstas, además de  
poseer un tipo genérico 'raw' donde converge con otras 'versiones'.

---
## TRABAJAR CON UNA COPIA DE IMAGEN 

#### Backing_files/overlays

La principal idea aquí, es la 'copia de seguridad'. Una vez se ha instalado el sistema  
operativo, puede trabajarse sobre un archivo de 'prueba/efecto'. Al que llamamos  
_Overlay_.  
Esto permite probar extensivamente un determinado GUEST, sin importar los cambios que  
hagamos, pues no serán aplicados al GUEST original, sino a la copia.  
La imagen del archivo que contiene la instalación original, o en un estado básico,  
la llamamos _BackingFile_.  

Para preparar este _entorno de prueba_ primero se crea una imagen en crudo, asignando el  
tamaño para la misma.

  ~~~  
  $ qemu-img create -f raw image_file.raw 10G  
  ~~~  

A continuación creamos el backing_file. Realmente no lo estamos creando, estamos formando  
la imágen en crudo, para que reconozca nuestro entorno de prueba, asociando ambos  
archivos: _raw/qcow2_ en este caso.  
Lo hacemos con la siguiente línea:

  ~~~  
  $ qemu-img create -o backing_file=image_file.raw,backing_fmt=raw \  
    -f qcow2 overlay.cow   
  ~~~  

Lo mas importante en este proceso, es asegurarnos de que el 'overlay' apunta al  
backing_file. Podemos comprobarlo con la aplicación _file_

  ~~~  
  $ file overlay.cow  
  ~~~  

> Tip: Cuando trabajamos con procedimientos de este tipo, es habitual separar los
> archivos, en distintos directorios. Una forma sencilla y eficaz de hacerlo
> sin tener que estar escribiendo una y otra vez rutas largas, es asignar
> la ruta a una variable.ejem: crear_backing.sh

  ~~~  
  #!/bin/sh  

  my_path=/ruta/a/directorio/respaldo  
  ~~~

Se que algunos me tacharán de novato, pero escribiendo las rutas directamente en la línea  
de comando, no conseguí de ninguna manera, que el vínculo entre ambos: backing-overlay,  
no se rompiese.  

> CAZADO:
> Al llamar al 'backing_file' en el proceso de instalación de la imagen, qemu, parece  
> no reconocer direcciones fuera del directorio que contiene la imagen 'base'. Esto  
> quiere decir que para instalar la imagen en el backing file es necesario encontrarse  
> en el directorio contenedor: mezcla las rutas absolutas/relativas.  



- La VM arranca con:  
  
  ~~~ 
  qemu -m 256 -hda test.img -kernel-kqemu & (obsoleto??)  
  ~~~  

> _-kemu-qkernel_ es un parámetro obsoleto no reconocido. He mirado en el Changelog de  
> la version instalada(-v2.6) pero no he encontrado ninguna referencia al respecto.  
> Podría ser que me pasase por alto.  
> Ademas, he tenido que forzar la instalación llamando a la imagen 'base' desde la  
> linea de comando, igual que si hiciese una instalacion normal.  



> EXPERIMENTAL: Debo probar hacer una copia de una instalación normal y una vez terminada la  
> instalación, formar el 'backing' sobre una copia de la imagen que ya contiene el sistema  
> operativo instalado.  
> En este caso, se conseguiría una imagen sin 'tocar' o como backup, sobre la cual hacemos  
> una copia, es decir, copiamos el archivo renombrándolo, antes de formar el 'backing'.  
> Una vez hecho esto lo creamos. Al crear el backing de esta forma, conseguimos  
> una imagen que no está tocada. 'El origen'.  
> Esto puede ser interesante si por algún motivo, no queremos crear una imagen en crudo,  
> o si queremos conservar una copia de una determinada instalación en un estado inicial.  
> También puede resultar útil, cuando hemos aplicado muchas actualizaciones a nuestra  
> imagen, y resulta mas complicado volver a un estado anterior, que comezar desde el  
> principio.  



#### SnapShots

> _to be continued_...

---  
## <a name="i3">CON O SIN CONEXION A INTERNET !!</a>

> __nota:__
>      Si se trabaja con el _overlay_, habrá que recordar actualizar el _backing_file_, de otra  
>      manera, estaremos escribiendo una y otra vez, las opciones necesarias para que la   
>      GUEST inicie a nuestro gusto. vínculo a trabajar con una copia de imagen  


Seguramente no seré la única persona que esté tratando de instalar un windows en una GUEST,  
a mi me dió algunos problemas con los dispositivos y drivers para la NIC. Que he solucionado  
añadiendo como apendice, la opción que detalla la línea de comando un poco más abajo.  

Da la casualidad que mi tarjeta de red es exactamente la que instala qemu, una Realtek,  
así que desconozco si a otras personas les será esto de ayuda.  

Pero para que conste el dato: cuando instalamos el sistema operativo en la guest, no hay  
que indicar ningún comando especial para tener acceso a internet. Por defecto, qemu  
establece el modo usuario.  

Mas bien el problema intuyo que viene dado desde el GUEST, cacawin(windrop in english)  
Es decir, que si estais buscando desde:  
     >>Panel de contro>>herramientas administrativas>>computer managament>>device manager  
     >>network adapter(dispositivo)  
La forma de instalar un dispositivo y su draiver, mejor quitaoslo de la cabeza.  
Porque hay chorrocientas alternativas y hay que pensar que qemu está instalando un dispositivo  
'virtual'.  

El dispositivo que ha quedado instalado en mi GUEST:  
  _Realtec RTL8139 family PCI Fast ethernet NIC_ (y su draiver con nombre similar/igual).  

En caso de que este dispositivo no funcione lo mejor es echar mano del manual de  
qemu-system-tu-_arquitectura-de-maquina_ y mirar que alternativas hay:  
>       -net nic[,vlan=n][,macaddr=mac][,model=type] [,name=name][,addr=addr][,vectors=v]  
>           Create a new Network Interface Card and connect it to VLAN n (n = 0 is the default). The  
>           NIC is an e1000 by default on the PC target. Optionally, the MAC address can be changed  
>           to mac, the device address set to addr (PCI cards only), and a name can be assigned for  
>           use in monitor commands.  Optionally, for PCI cards, you can specify the number v of  
>           MSI-X vectors that the card should have; this option currently only affects virtio  
>           cards; set v = 0 to disable MSI-X. If no -net option is specified, a single NIC is  
>           created.  QEMU can emulate several different models of network card.  Valid values for  
>           type are "virtio", "i82551", "i82557b", "i82559er", "ne2k_pci", "ne2k_isa", "pcnet",  
>           "rtl8139", "e1000", "smc91c111", "lance" and "mcf_fec".  Not all devices are supported  
>           on all targets.  Use "-net nic,model=help" for a list of available devices for your  
>           target.  


>> Solo he podido probar esta teoría en mis máquinas!   

Añadiendo la opcion -net parametro _nic_, qemu instala una targeta virtual de red genérica.  
De hecho, el manual que sugiere gentoo, es el que me ha funcionado a mi. La versión de qemu  
que corre mi máquina es la 2.6, es posible que en sucesivas actualizaciones vemamos otros  
cambios.  

El comando quedaría algo así:  

  ~~~  
qemu-system-(arch) -net nic,model8139 ...   
  ~~~  

De esta forma la MAC de la VM tendrá un identificador por defecto.  
Esto puede ser un inconveniente, si corremos mas de una máquina, y queremos tener acceso  
a internet en todas ellas, puesto que la aplicación genera por defecto, siempre la  
misma MAC. 

Para que esto no ocurra debe indicarse un identificador. Reempaza las "X" con números  
hexadecimales arbitrarios, pero recuerda conservar las primeras dos cifras, que hacen  
referencia al id de fabricante(qemu).  
  ~~~
$ qemu-system-i386 -net nic,macaddr=52:54:XX:XX:XX:XX -net vde disk_image
  ~~~
Otro problema con el que nos encontraremos, es que la tarjeta virtual que estamos creando  
tiene asociado otro compenente, una especie de CTR o conector que debe ser único para  
cada GEST.

Hay dos formas básicas de dotar a la VM con conexión a internet:

  - Modo usuario (slirp)
  - Modo Tap

####Modo usuario:
  ~~~
-netdev user,id=mynet0,net=192.168.76.0/24,dhcpstart=192.168.76.9  
  ~~~

> _Notas:_ 
>
>   También es razonable pensar en virtualizar aplicaciones aisladas. Es posible que La  
>   Guest solo pueda comunicarse con otra GUEST. Habrá que averiguar si es posible acceder  
>   a una partición fuera de VM!!  
>
>   Otra idea es probar qemu-ga. Éste es un demonio que funciona desde dentro de la  
>   SUPUESTA, así que en teoría, el host via injection/algo puede gestionar la particion  
>   de la VM, pero habrá que averiguar que tipo de operaciones puede hacer GUEST-AGENT.  
>
>   La idea es mantener la VM simple, ya que por razones obvias, esto mejora su  
>   rendimiento, además el objeto de estas 'maquinas' es romperlas. Y ya se  
>   sabe que pasa cuando uno entra a cuchillo en algún lado(sin saber)...  


#### Modo Tap
> to be continued...

---   
## EL LOOPBACK 

La traducción de loopback significa: bucle hacia atrás(ma o meno), o 'camino de  
regreso'. La idea es utilizar una partición o disco, que se encuentra fuera de la  
imagen de la VM.  

Antes de seguir, debo recordar que las operaciones con particiones y sobre módulos  
que afectan directamente al _kernel_, hay que hacerlas con permisos de administrador.  
Por precaución, siempre es recomendable hacer este tipo de opereaciones con la  
VM apagada. De otra forma, se corre el riesgo de corromper los datos de la imagen.  

En determidas ocasiones, la máquina virtual no tiene conexión a internet. Es el caso  
de una instalación con Qemu. Así que la mejor forma de comunicarnos con la VM es  
mediante la técnica del _loopback_.

Las técnicas que describiré a continuación, pueden llevarse a cabo sobre particiones con  
formato de disco usease formateadas: ejem Ext3, NTFS, FAT32 etc. o sobre una imagén sin  
una partición en concreto.

Esto quiere decir, que puede montarse una copia de "respaldo" de _old-games_, en una imagen  
lo suficientemente grande, sin necesidad de crear una partición dentro de la imagen.  
En realidad lo que ocurre, es que la partición abarca todo el disco, no significa que no  
haya partición, significa que todo el disco está ocupado por una única partición.  
En este "marco" qemu no tiene problema para leer la tabla de nodos de partición, porque  
solo hay una, con un formato determinado!!

Así que antes de describir las dos alternativas, quiero dejar anotado un concepto que puede  
ser aplicado a ambas técnicas: _montaje simple_.

Si _no_ se crea una partición en la imagen(la VM), los datos podrán ser montados sobre  
cualquier formato. Sin embargo, si tenemos alojadas particiones dentro de la imagen,  
únicamente podremos montarlas en formato raw(crudo en inglés).  
Esto es para que qemu pueda manejar las particiones alojadas.  

En este caso como trabajaremos sobre una imagen ISO, parece apropiado seguir los pasos  
descritos al principio del artículo. Crear la caja vaía, y escribirla en el formato  
apropiado. Pero como problamente no queramos lanzar otra GUEST, sino únicamente acceder  
al contenido del la imagem. La operación de calcular el offset de la partición, puede  
ser omitida _-ver mas adelante_. 

Esto es de lo que hablaba: el _montaje simple_. Puede determinarse mirando el contenido de  
la imagen:

  ~~~  
 $ file imagen.iso  
    imagen.iso: ISO 9660 CD-ROM filesystem data 'GRTMPVOL_EN' (bootable)  
  ~~~

Vemos que únicamente contiene una partición. A continuación, tan sólo queda montar la imagen.  
Para esto utilizamos la aplicación _losetup:_  

  ~~~  
    $ losetup /dev/loop0 /punto_de_montaje/imagen.iso
  ~~~  

En caso de utilizar este método _montaje simple_, para evitar que el sistema nos devuelva
algún mensaje de aviso, acerca de los permisos con los que se monta la unidad, podemos
especificar que lo haga en modo solo lectura.

  ~~~  
    # mount -o ro,loop image.iso /mnt/point
  ~~~


> __nota:__ aquí va otra nota sobre el uso de los shasum y file, sobre la importancia  
> de hacer las comprobaciones oportunas en cuanto a imágenes descargadas. Y un especial  
> comentario acerca del cambio que se produce en un sha, cuando queremos montar una imagen  
> con permisos de escritura. IMPORTANTE INVESTIGAR!  

#### MONTAR UN LOOPBACK PARA COMUNICARNOS CON LA VM SIN CONEXION 

  Calcular el _offset_ antes de montar la imagen de disco.  
    
 1. Asociar el dispositivo de imagen de disco, a la partición que vayamos a montar.
    ~~~
    tux@venus:~> losetup /dev/loop0 /images/sles11sp1_base.raw  
    ~~~
    
 2. Tamaño de sector y número de inicio de sector, de la partición a montar.
    ~~~
    tux@venus:~> fdisk -lu /dev/loop0  
    
    Disk /dev/loop0: 4294 MB, 4294967296 bytes  
    255 heads, 63 sectors/track, 522 cylinders, total 8388608 sectors  
    Units = sectors of 1 * 512 = 512[1] bytes  
    Disk identifier: 0x000ceca8  
  
           Device Boot      Start         End      Blocks   Id  System  
    /dev/loop0p1              63     1542239      771088+  82  Linux swap  
    /dev/loop0p2   *     1542240[2]    8385929     3421845   83  Linux  
    ~~~
  
    [1] Tamaño del sector.

    [2] Sector de inicio de la partición.

 3. Calcular el _offset_ de inicio, de la partición.

    sector_size * sector_start = 512 * 1542240 = 789626880

 4. Borrar el loop y montar la partición, dentro de la imagen de disco. Con el cálculo del offset  
    dentro del directorio ya preparado.        

    ~~~
    tux@venus:~> losetup -d /dev/loop0  
    tux@venus:~> mount -o loop,offset=789626880 \  
    /images/sles11sp1_base.raw /mnt/sles11sp1/  
    tux@venus:~> ls -l /mnt/sles11sp1/  
    total 112  
    drwxr-xr-x   2 root root  4096 Nov 16 10:02 bin  
    drwxr-xr-x   3 root root  4096 Nov 16 10:27 boot  
    drwxr-xr-x   5 root root  4096 Nov 16 09:11 dev
    [...]  
    drwxrwxrwt  14 root root  4096 Nov 24 09:50 tmp  
    drwxr-xr-x  12 root root  4096 Nov 16 09:16 usr  
    drwxr-xr-x  15 root root  4096 Nov 16 09:22 var  
    ~~~  

 5. Copiar uno o mas archivos dentro de la partición montada y desmontar al terminar.

    tux@venus:~> cp /etc/X11/xorg.conf /mnt/sles11sp1/root/tmp  
    tux@venus:~> ls -l /mnt/sles11sp1/root/tmp  
    tux@venus:~> umount /mnt/sles11sp1/  

 
#### LOOPBACK PARA UNA IMAGEN (USANDO MODUOS EN EL KERNEL)

Aquí primero preparamos el dispositivo que será leído por el módulo de kernel NBD.  
Para ello debemos tener cargado dicho módulo o cargarlo en todo caso. Recuerda que   
para llevar a cabo este tipo de operaciones, debemos escalar privilegios.

Primero comprobamos si tenemos instalados los módulos que vamos  
a usar  ... normalmente en /lib/... (editar)  
Comprobar si el módulo está cargado o no, en el sistema. Puede determinarse con:

  ~~~  
    $ lsmod |cat -n |grep modulo-en-cuestion  
  ~~~

- La primera instrucción lista los módulos cargados en el kernel.
- Através de tubería cuantificamos su número, por razones de stress!!
- y le pasamos un filtro grep, para concretar la salida.

Si el modulo no está cargado, lo cargamos dándole un parámetro 'max_part'  
para poder acceder a los nodos de cada una de las particiones.  
En caso de no iniciar la variable, como el valor por defecto es 0(cero)  
podrá accederse al disco, pero no a los nodos de ninguna de las particiones  
 ...

Esto puede hacerse en una misma línea(root):  
  ~~~  
    # modprobe nbd max_part=N  
  ~~~

  - 'N' representa el número de particiones que tiene la imagen que vamos a montar  
  Por lo que teniendo esto en cuenta, debe ajustarse con criterio!!  
  Si se trata de una imagen, sin una partición especifica, puede omitirse el  
  parametro.  
 
> Dato sin verificar!

Si el módulo está cargado, lo mejor es descargarlo y cargarlo de nuevo, iniciando la  
variable. En Debian esto parece que tiene un bug. Cuando comprobamos la información  
del módulo(antes y despues de la asignación):
  ~~~  
    # modinfo nbd  
  ~~~

Si está cargado, lo descargamos:  
  ~~~  
    # rmmod nbd  
  ~~~
---
...vemos que aparece la ĺinea, pero no el entero! parece un bug. Es la segunda línea  
empezando por abajo. 
> _nota:_ deberías comprobar si en el mailing de Debian se ha escrito el 'report'.  

__antes:__
  ~~~
filename:       /lib/modules/algo_aqui/kernel/drivers/block/nbd.ko  
license:        GPL  
description:    Network Block Device  
depends:  
intree:         Y  
vermagic:       algo_aqui-tete SMP mod_unload modversions 086  
parm:           nbds_max:number of network block devices to initialize (default: 16) (int)  
parm:           max_part:number of partitions per device (default: 0) (int)  
parm:           debugflags:flags for controlling debug output (int)  
  ~~~

__después:__
  ~~~
    # modprobe nbd max_part=8  
  ~~~  

  ~~~  
  # modinfo nbd
filename:       /lib/modules/algo-aqui/kernel/drivers/block/nbd.ko  
license:        GPL  
description:    Network Block Device  
depends:  
intree:         Y  
vermagic:       algo-aqui SMP mod_unload modversions 086  
parm:           nbds_max:number of network block devices to initialize (default: 16) (int)  
parm:           max_part:number of partitions per device (default: 0) (int)  
parm:           debugflags:flags for controlling debug output (int)  
  ~~~


Este comando identifica la imagen, como un dispositivo de bloque llamado  
/dev/nbd0, y la partición dentro de éste, como sub-dispositivo, que sería:  
/dev/nbd0p1
  ~~~  
    qemu-nbd -c /dev/nbd0 _vdi-file_  
  ~~~

 1. CARGAMOS EL MÓDULO 

 modprobe nbd -- Esto carga el módulo de no estar cargado.  
 modprobe nbd max_part=16  
  
 2. A continuación preparamos el dispositivo donde montaremos la unidad.
 Este proceso inicia una especie de servidor. Realmente la carga en memoria es mínima, es
 decir, no es como si lanzásemos Apache!!!

 qemu-nbd -c /dev/nbd0/ /path/to/vhd_file -- Esto conecta el dispositivo.
 partprobe /dev/nbd0  -- indica al SO los cambios que se han llevado a cabo en la 
                         tabla de particiones.

 3. Este último paso, es el que realmente monta la unidad virtual en el sistema.
 
 mount /dev/nbd0p1 /imagen/a/montar(vhd en este caso!!)

     RECUERDA DESMONTAR LA UNIDAD Y EL DISPOSITIVO CUANDO TERMINES.

 umount /imagen/montada(vhd) -- Desmontamos imagen.
 qemu-nbd -d /dev/nbd0 -- desconectamos dispositivo.


## LANZAR LA VM APUNTANDO AL SERVIDOR NBD

 $QEMU -object tls-creds-x509,id=tls0,dir=$HOME/.pki/qemutls,endpoint=client \
       -drive driver=nbd,host=localhost,port=10809,tls-creds=tls0 \
       /path/to/img






#### http://bethesignal.org/blog/2011/01/05/how-to-mount-virtualbox-vdi-image/ ####

 

 Ahora podríamos ejecutar cfdisk en el dispositivo de bloque, y montarlo
 como partición individual.

 mount /dev/nbd0p1 /mnt -- "/mnt" es el punto de montaje.


 Al terminar podemos desmontar la unidad y el dispositivo, así.

 unmount /mnt
 qemu-nbd -d /dev/nbd0
###################################################################

 You can use qemu-nbd in Linux to access a disk image as if it were a block device.
 Here are some examples of operations that can be performed from a live Knoppix terminal.

   su 
   modprobe nbd
   qemu-nbd --read-only --connect=/dev/nbd0 --format=vpc <vhd_file_name>

   If VHDX format:

   qemu-nbd --connect=/dev/nbd0 --format=VHDX <vhdx_file_name>
   ddrescue --verbose --force /dev/nbd0 /dev/sda  # write image to /dev/sda

#### Write one partition: 

   nbd --partition=2 --read-only --connect=/dev/nbd2 --format=vpc <vhd_file_name> 
   ddrescue --verbose --force /dev/nbd2 /dev/sda2 # write partition 2 of image to /dev/sda2

#### Mount partition:

  qemu-nbd --partition=2 --read-only --connect=/dev/nbd2 --format=vpc <vhd_file_name>
  mount /dev/nbd2 /mnt 

#### Unmount and disconnect image file:

  umount /mnt 
  qemu-nbd --disconnect /dev/nbd2

#### To convert a vhd image to raw (less usable)

qemu-img convert -f raw -O vpc something.img something.vhd

#### To convert a vhd image to cow2 (the up to date qemu format)
qemu-img convert -f qcow2 -O vpc something.img something.vhd

##                  E X P E R I M E N T A L                     

[Foo](#foo)   
   VIRTIO -- https://wiki.archlinux.org/index.php/QEMU#qxl
   
   virtio-vga / virtio-gpu is a paravirtual 3D graphics driver based on virgl. Currently a work in
   progress, supporting only very recent (>= 4.4) Linux guests. 

 QEMU offers guests the ability to use paravirtualized block and network devices using the virtio
 drivers, which provide better performance and lower overhead.
 
 A virtio block device requires the option -drive instead of the simple -hdX plus if=virtio:
 
     $ qemu-system-i386 -boot order=c -drive file=disk_image,if=virtio
 
 Note: -boot order=c is absolutely necessary when you want to boot from it. There is no 
 auto-detection as with -hdX
 
 Abmos  the same goes for the network:
 
 $ qemu-system-i386 -net nic,model=virtio
 
 Note: This will only work if the guest machinethas drivers for virtio devices. Linux does, and the
 required drivers are included in Arch Linux, but there is no guarantee that virtio devices will work
 with other operating systems.

## AGRADECIMIENTOS

Documentation/Networking --[QEMU][QEM]  
Gente de fedora --[snapshots-handout][fedora]  
ArchWiki --[QEMU][archi]  
Suse --[QEMU][suse]  
Markdowns y otras recomendaciones --[Javier Cristóbal][Markdown] \- [productividad mac][limni]  


---
[QEM]: http://wiki.qemu.org/Documentation/Networking
[fedora]: https://kashyapc.fedorapeople.org/virt/lc-2012/snapshots-handout.html
[archi]: https://wiki.archlinux.org/index.php/QEMU#qxl
[suse]: https://www.suse.com/documentation/sles11/book_kvm/data/cha_qemu_guest_inst_qemu-img.html 
[Markdown]: http://markdown.es/sintaxis-markdown/
[limni]: http://limni.net/blog/

 

-->



1. [Titulo de algo aqui](#referencia)  
---
1. <a name="referencia">Titulo de algo</a>  

---
man qemu-system:

-net nic
Create a new Network Interface Card and connect it to VLAN n (n = 0 is the default). The
           NIC is an e1000 by default on the PC target.






