#### Consideraciones

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
