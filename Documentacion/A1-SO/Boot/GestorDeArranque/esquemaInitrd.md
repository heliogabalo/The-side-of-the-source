1. Esquema de initrd

99. Referencias y agradecimientos

---

El gestor de arranque cargará el _kernel_ y el sistema de archivo inicial, en la memoria y  
luego activará el núcleo, pasandole la dirección de memoria de la imagen. Al final de la
secuencia de arranque, el _kernel_ intentará determinar el formato de la imagen, desde sus  
_primeros_ bloques de datos, lo que podría llevarlo a un esquema del tipo _initrd_ o _initramfs_.

#### Esquema de initrd

En el esquema _initrd_, la imagen podría ser una imagen del _sistema de archivos_ -opcionalmente  
comprimida, estando disponible através un dispositivo de bloque especial `/dev/ram`, que es  
entonces montado como sistema de archivo raíz inicial. El controlador para este sistema de  
archivos, debe estar compilado estáticamente en el _kernel_. 

Muchas distribuciones, usaron originalmente una imagen de sistema de archivo, tipo _ext2_,  
mientras que otros -como _Debian 3.1_, utilizaron `cramfs`, con objeto de arrancar, en sistemas  
con memoria limitada, por que la imagen `cramfs` puede ser montada _in-situ_, sin necesidad
de espacio extra para su descompresión.
Una vez, el sistema de archivo raíz inicial es levantado, el _kernel_ ejecuta `/linuxrc` como  
su primer proceso; cuando sale, el _kernel_ asume que el lsistema de archivo raíz "real", ha  
sido montado y ejecuta `/sbin/init` para empezar el proceso  normal de arranque en el espacio  
de usuario.  


#### Referencias y agradecimientos
[Initial_ramdisk][https://en.wikipedia.org/wiki/Initial_ramdisk]
