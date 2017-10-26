## Consideraciones

#### Encontrar punto de montaje asiciado al _LV_.

El gestor _LVM_ se construyó para que arrojase información via `...display` o `...s`
acerca del dispositivo de bloque, no del sistema de fichero. Por lo que si estamos
buscando como encontrar el punto de montaje de un determinado _LV_, deberemos
recurrir a:

		# mount | grep volume_group-lvname

¿Alguno recuerda el comentario que hice sobre los `guiones`?. Maldito _lol_!!.
> __caso práctico__: _LV_ llamado "mi-volumen" montanodo sobre `/mnt/mi_puntoM`
, el _PV_ se llama "infierno".
`# mount|grep infierno-mi--volumen`.
Esto funciona sobre una distribución Fedora. Hay otra notación por _siaca!_.
		# mount |grep VG/lvname

#### Ruta asociada a SeLinux

En teoría deberíamos utilizar por defecto la ruta configurada para que SeLinux
no dé problemas, esto es: `/var/lib/libvirt/images/`


Al parecer el disco(LV) me esta dando problemas:
		ls: leyendo el directorio '/mnt/home-extra/': Input/output error

Tras completar la copia de la captura, pude acceder normalmente al espacio de
disco donde coloque el _backup_ de la _captura_. Sin embargo, al día siguiente
el simple listado del directorio, arroja la salida _I/O_ indicada unas pocas
líneas arriba.

Puede ser debido al _AF_ del sector de disco, con el que se construyeron las
particiones. El disco principal sé que dispone de esta capacidad.
Por otro lado los discos USB almacenan la memoria de forma completamente
distinta ya que no se trata de un cambio magnético como ocurre con un HDD, sino
de un cambio de estado que se produce en la célula de memoria.

---

To create a logical volume to be allocated from a specific physical volume in
the volume group, specify the physical volume or volumes at the end at the
lvcreate command line. The following command creates a logical volume named
testlv in volume group testvg allocated from the physical volume /dev/sdg1,

lvcreate -L 1500 -ntestlv testvg /dev/sdg1

Para crear un _LV_ que pueda ser recolocado sobre un específico _PV_ dentro de
un _VG_, se debe especificar el _PV_ o volúmenes al final del comando `lvcreate`.
El siguiente comando crea un _LV_ llamado `testlv` en el _VG_ `testvg` alojado en
`/dev/sdg1`:

		lvcreate -L 1500 -ntestlv testvg /dev/sdg1