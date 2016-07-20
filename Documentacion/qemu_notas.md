
1. PROCESO DE INSTALACION DE UNA IMAGEN
    1. Crear imagen
    2. Convetir imagen

2. TRABAJAR CON UNA COPIA DE IMAGEN
  - 2.1 Backing-files/overlays
  - 2.2 Snapshots 
3. CON O SIN CONEXION A INTERNET
4. COMO MONTAR UN LOOPBACK PARA COMUNICARNOS CON LA VM SIN CONEXION
5. LOOPBACK PARA UNA IMGEN (USANDO MODULOS EN EL KERNEL)
  - 5.1 Lanzar la VM apuntando al servidor NBD
6. EXPERIMENTAL

---
## PROCESO DE INSTALACION DE UNA IMAGEN ##

 Bien sea porque tenemos el disco original (en este caso un SO windows)  
 o bien porque lo hayamos descargado, deberemos antes CREAR una imagen GUEST  
 con la que  QEMU, pueda trabajar.

    1. Para esto primero creamos la imagen. Una "caja" vacía.  
  ~~~
 qemu-img create -f qcow2 mi_imagen.img 1G
  ~~~

 Aquí el flag "-f" indica el tipo de formato con el que será creada nuestra imagen (aún vacia).
 También indicamos el archivo imagen y el tamaño en Gigabytes.

 2.- Instalación de SUPUESTO OS en la imágen previamente creada:  
  ```bash  
 qemu -m 256 -hda mi_imagen.img -cdrom winxpsp2.iso -boot d  
  ```
 Este comando anterior es un poco confuso.
   - Habrá que sustituir "qemu" con el comando apropiado, en relación a la arquitectura
   del sistema operativo GUEST con el que se vaya a trabajar. En este caso sería:
   qemu-system-i386
   - Nuevamente el flag -m indica la memoria RAM para el SUPUESTO SO.
   - La siguiente opción -hda indica el archivo imagen donde vamos a instalar la imagen del SO.
   - Sigue la opción -cdrom, parece indicar el dispositivo físico un 'CD', pero todo apunta
   a que se trata de una denominación para diferenciarlo de la partición GUEST que acabamos
   de crear. Es decir, que utilizaremos el mismo flag '-cdrom' para tratar con una imagen
   descargada en el disco duro, o una imagen que previamente hayamos 'quemado' en un 'CD'.
   La diferencia es que para utilizar un 'CD' a la hora de hacer la instalación en nuestra
   'caja vacía' habrá que indicar la ruta hacia el dispositivo ejem. /dev/cdrom
   La opción -boot d indica como 'cadena' la letra que será usada en el arranque del sistema.
   Es exactamente igual a como interpreta la BIOS el 'orden' de arranque de sistema de nuestro 
   HOST.
   *  'a' y 'b' para la floppy
   *  'c' para el disco duro
   *  'd' para el CD-ROM
   *  'n-p' arranque desde RED. Opcion muy interesente para un GUEST. Investigar!!!
   Desde Linux, la cadena que representa el dispositivo de arranque, está muy claro,
   (pues nosotros no usamos letras para esto). Así que 'c' claramente representa al
   disco duro y 'd' a un CD-ROM.
   Desde una perspectiva <Win@> habrá que asegurarse, pués windows utiliza letras para
   denominar los dispositivos de almacenamiento. De momento a mi plin!

   ------------------------------
## TRABAJAR CON UNA COPIA DE IMAGEN ##

   La principal idea aquí, es la 'copia de seguridad'. Una vez se ha instalado el sistema
   operativo, puede trabajarse con una copia de la imagen, resultado de la instalación.
   Esto permite probar extensivamente un determinado GUEST, sin importar los cambios que
   hagamos, pues no serán aplicados al GUEST original, sino a la copia.

   Son necesarios dos pasos básicos:

   1.- Cremaos una imagen 'qemu' con esta funcionalidad:

     <qemu-img create -f qcow2 -o backing_file=winxp.img test01.img 1M>

     Al llamar al 'backing_file' en el proceso de instalación de la image, qemu, parece 
     no reconocer direcciones fuera del directorio que contiene la imagen 'base'. Esto 
     quiere decir que para instalar la imagen en el backing file es necesario encontrarse 
     en el directorio contenedor.
     nota: mezcla las rutas absolutas/relativas.
     
     Con el comando 'backing_file' conseguimos establecer una copia 'base' que no será
     alterada. Los cambios en el SUPUESTO sólo serán aplicados a la imagen copia.
     Habrá que tener en cuenta el guardar los cambios aplicados dentro del entorno 
     alternativo, pues de otro modo, perderemos todo el tabajo cuando borremos la 
     imagen.

   2.- qemu -m 256 -hda test.img -kernel-kqemu & (obsoleto??)
     -kemu-qkernel es un parámetro obsoleto no reconocido. He mirado en el Changelog de
     la version instalada(-v2.6) pero no he encontrado ninguna referencia al respecto.
     Podría ser que me pasase por alto.
     Ademas, he tenido que forzar la instalación llamando a la imagen 'base' desde la 
     linea de comando, igual que si hiciese una instalacion normal.

     Por tanto la línea de entrada quedaría así:
     qemu-system-i386 -m 256 -hda copia(overlay).img -cdrom base_name(backing).img -boot <string>

   -----------------------------------

##   CON O SIN CONEXION A INTERNET !! ##

   Añadiendo la opcion -net parametro <nic> qemu instala una tqrgeta virtual de red genérica.

   El comando quedaría algo así:

   qemu-system-<arch> -net nic \
     ... \
     -<mas opciones>


   De esta forma la MAC de la VM tendrá un identificador por defecto. 
   Esto puede ser un inconveniente, si corremos mas de una máquina, y queremos tener acceso
   a internet en todas ellas, puesto que la aplicación genera por defecto, siempre la 
   misma MAC.# 

   Para que esto no ocurra sebe indicarse un identificador. Reempaza las "X" con números 
   decimales arbitrarios, pero recuerda conservar las primeras dos cifras, que hacen
   referencia al id de fabricante(qemu)
   
   $ qemu-system-i386 -net nic,macaddr=52:54:XX:XX:XX:XX -net vde disk_image

   Otro problema con el que nos encontraremos, es que la tarjeta virtual que estamos creando
   tiene asociado otro compenente, una especie de CTR o conector que debe ser único para 
   cada GEST.

   Hay dos formas básicas de dotar a la VM con conexión a internet:

     - Modo usuario (slirp)
     - Modo Tap

     Modo usuario:

     -netdev user,id=mynet0,net=192.168.76.0/24,dhcpstart=192.168.76.9

   ------------------------------
   Notas: 
     Al seguir éste segundo método de instalación, he podido comprobar que el proceso
     de conectar el dispositivo y luego montar la unidad GUEST al mismo, lo hace qemu
     automáticamente, por lo que el uso de los scripts de arranque y parada que he
     escrito, son poco útiles. Cuidado NO UTILIZAR, para evitar duplicados. 

     Cabe pensar que para el proceso de arranque de una VM, habrá que confeccionar otros
     scripts específicos, con los que poder dar más opciones al sistema GUEST.

     También es razonable pensar en virtualizar aplicaciones aisladas. Es posible que La
     Guest solo pueda comunicarse con otra GUEST. Habrá que averiguar si es posible acceder
     u una partición fuera de VM!!

     Otra idea es probar qemu-ga. Éste es un demonio que funciona desde dentro de la
     SUPUESTA, así que en teoría, el host via injection/algo puede gestionar la particion
     de la VM, pero habrá que averiguar que tipo de operaciones puede hacer GUEST-AGENT.

     La idea es mantener la VM simple, ya que por razones obvias, esto mejora su 
     rendimiento, además el objeto de estas 'maquinas' es romperlas. Y ya se 
     sabe que pasa cuando uno entra a cuchillo en algún lado(sin saber)...
     Por otro lado puede que me convenga retomar la programación con Ogre3D. 
     (en Linux es un DESASTRE!!).


###############################################################
###############################################################

   COMO MONTAR UN LOOPBACK PARA COMUNICARNOS CON LA VM SIN CONEXION

  Mounting Disk Image by Calculating Partition Offset

 1. Set a loop device on the disk image whose partition you want to mount.

    tux@venus:~> losetup /dev/loop0 /images/sles11sp1_base.raw

 2. Find the sector size and the starting sector number of the partition you want to mount.

    tux@venus:~> fdisk -lu /dev/loop0

    Disk /dev/loop0: 4294 MB, 4294967296 bytes
    255 heads, 63 sectors/track, 522 cylinders, total 8388608 sectors
    Units = sectors of 1 * 512 = 512[1] bytes
    Disk identifier: 0x000ceca8

           Device Boot      Start         End      Blocks   Id  System
    /dev/loop0p1              63     1542239      771088+  82  Linux swap
    /dev/loop0p2   *     1542240[2]    8385929     3421845   83  Linux

    [1] The disk sector size.

    [2] The starting sector of the partition.

 3. Calculate the partition start offset:

    sector_size * sector_start = 512 * 1542240 = 789626880

 4. Delete the loop and mount the partition inside the disk image with the calculated offset on a
    prepared directory.

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

 5. Copy one or more files onto the mounted partition and unmount it when finished.

    tux@venus:~> cp /etc/X11/xorg.conf /mnt/sles11sp1/root/tmp
    tux@venus:~> ls -l /mnt/sles11sp1/root/tmp
    tux@venus:~> umount /mnt/sles11sp1/

###############################################################



###############################################################
                  E X P E R I M E N T A L                     #
###############################################################
   
   VIRTIO -- https://wiki.archlinux.org/index.php/QEMU#qxl
   
   virtio-vga / virtio-gpu is a paravirtual 3D graphics driver based on virgl. Currently a work in
   progress, supporting only very recent (>= 4.4) Linux guests. 

 QEMU offers guests the ability to use paravirtualized block and network devices using the virtio
 drivers, which provide better performance and lower overhead.
 
 A virtio block device requires the option -drive instead of the simple -hd* plus if=virtio:
 
     $ qemu-system-i386 -boot order=c -drive file=disk_image,if=virtio
 
 Note: -boot order=c is absolutely necessary when you want to boot from it. There is no 
 auto-detection as with -hd*.
 
 Abmos  the same goes for the network:
 
 $ qemu-system-i386 -net nic,model=virtio
 
 Note: This will only work if the guest machinethas drivers for virtio devices. Linux does, and the
 required drivers are included in Arch Linux, but there is no guarantee that virtio devices will work
 with other operating systems.
 
####################################################################
Aquí primero preparamos el dispositivo que será leído por el módulo de
kernel NBD. Para ello debemos tener cargado dicho módulo o cargarlo en 
todo caso. Recuerda que para llevar a cabo este tipo de operaciones en
  el kernel debemos escalar privilegios.
  

## 1- CARGAMOS EL MÓDULO ##

 modprobe nbd -- Esto carga el módulo de no estar cargado.
 modprobe nbd max_part=16  -- Esto es una opción del módulo que no tengo muy clara, INVESTIGAR. 
 
 2.- A continuación preparamos el dispositivo donde montaremos la unidad.
 Este proceso inicia una especie de servidor. Realmente la carga en memoria es mínima, es
 decir, no es como si lanzásemos Apache!!!

 qemu-nbd -c /dev/nbd0/ /path/to/vhd_file -- Esto conecta el dispositivo.
 partprobe /dev/nbd0  -- indica al SO los cambios que se han llevado a cabo en la 
                         tabla de particiones.

 3.- Este último paso, es el que realmente monta la unidad virtual en el sistema.
 
 mount /dev/nbd0p1 /imagen/a/montar(vhd en este caso!!)

     RECUERDA DESMONTAR LA UNIDAD Y EL DISPOSITIVO CUANDO TERMINES.

 umount /imagen/montada(vhd) -- Desmontamos imagen.
 qemu-nbd -d /dev/nbd0 -- desconectamos dispositivo.

###############################################################
###############################################################

 LANZAR LA VM APUNTANDO AL SERVIDOR NBD

 $QEMU -object tls-creds-x509,id=tls0,dir=$HOME/.pki/qemutls,endpoint=client \
       -drive driver=nbd,host=localhost,port=10809,tls-creds=tls0 \
       /path/to/img




###############################################################
###############################################################

 Por qué convertir imágenes antes de instalarlas:
 
 qemu-img convert -f source.vhd -O qcow2 destination.qcow2
 
 - Parece que ha habido algún problemilla con la nomenclatura del comando
 La siguiente devuelve la imagen convertida, sin ningún error desde fd2.

    < qemu-img convert -O qcow2 filename file_output > (autodetectada??)


 Qemu tiene el conversor de imagenes mas versatil, en relación a otros emuladores.
 Esto lo convierte en una herramienta indispensable a la hora de trabajar con VMs.
 Así como otros emuladores, presentan limitaciones a la hora de trabajar con imagenes
 específicas (extension del archivo) qemu es capaz de interpretar una gran variedad de
 éstas, además de poseer un tipo genérico 'raw' donde converge con otras 'versiones'.





###############################################################
##############################################################
     LOOPBACK PARA UNA IMGEN (USANDO MODULOS EN EL KERNEL)
###############################################################
###############################################################

#### http://bethesignal.org/blog/2011/01/05/how-to-mount-virtualbox-vdi-image/ ####

 Primero comprobamos si tenemos instalados los módulos que vamos
 a usar  ... normalmente en /lib/... (editar)
 Comprobar si el módulo está cargado o no, en el sistema. Puede determinarse con:

 lsmod |cat -n |grep <modulo-en-cuestion> 

 - La primera instrucción lista los módulos cargados en el kernel.
 - Através de tubería cuantificamos su número, por razones de stress!!
 - y le pasamos un filtro grep, para concretar la salida.

 Si el modulo no está cargado, lo cargamos dándole un parámetro 'max_part'
 para poder acceder a los nodos de cada una de las particiones.
 En caso de no iniciar la variable, como el valor por defecto es 0(cero)
 podrá accederse al disco, pero no a los nodos de ninguna de las particiones
  ...

 Esto puede hacerse en una misma línea:

 modprobe nbd max_part=<N>

   - 'N' representa el número de particiones que tiene la imagen que vamos a montar
   Por lo que teniendo esto en cuenta, debe ajustarse con criterio!!
   Si se trata de una imagen, sin una partición especifica, puede omitirse el 
   parametro.

 Si el módulo está cargado, lo mejor es descargarlo y cargarlo de nuevo, 
 iniciando la variable. En Debian esto parece que tiene un bug. Cuando comprobamos
 la información del módulo(antes y despues de la asignación):

 modinfo nbd

 ...vemos que aparece la ĺinea, pero no el entero! parece un bug. 
 nota: deberias comprobar en el mailing de Debian se ha escrito el 'report'.

 Este comando identifica la imagen, como un dispositivo de bloque llamado
 /dev/nbd0, y la partición dentro de éste, como sub-dispositivo, que sería:
 /dev/nbd0p1

 qemu-nbd -c /dev/nbd0 <vdi-file> 

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

# Write one partition: 

   nbd --partition=2 --read-only --connect=/dev/nbd2 --format=vpc <vhd_file_name> 
   ddrescue --verbose --force /dev/nbd2 /dev/sda2 # write partition 2 of image to /dev/sda2

# Mount partition:

  qemu-nbd --partition=2 --read-only --connect=/dev/nbd2 --format=vpc <vhd_file_name>
  mount /dev/nbd2 /mnt 

# Unmount and disconnect image file:

  umount /mnt 
  qemu-nbd --disconnect /dev/nbd2

# To convert a vhd image to raw (less usable)

qemu-img convert -f raw -O vpc something.img something.vhd

## To convert a vhd image to cow2 (the up to date qemu format)
qemu-img convert -f qcow2 -O vpc something.img something.vhd
