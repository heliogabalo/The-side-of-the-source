## Restaurar backups

#### Restauración del _LVM_.
El Gestor de volúmenes lógicos, guarda un registro de ls _VG's_ creados en el
sistema. Esto resulta muy útil a la hora de restaurar un esquema, por ejemplo
para una máquina virtual:
    # ls /etc/lvm/archive

Obviamente se trata _únicamente_ del esquema, es cierto que registra tamaño,
nombres(_PV's, LV's_), _UUID_, en definitiva, toda la información relacionada
con el _LVM_ en cuestión. Sin embargo lo que __no__ guarda son los __datos!__.

Los datos deberán haber sido previamente guardados, para poder recuperarse.
Así que lo primero, será abrise paso hasta el directorio y, determinar cuál
de ellos es el más conveniente.

Una vez hecho esto, bastará fijarse en el _UUID(universally unique identifier)_
y el _archivo de configuración_:
    # pvcreate --uuid "xxxxxx-xxxx-xxxx-xxxx-xxxx-xxxx-xxxxxx" \
    --restorefile /etc/lvm/archive/vg_storage_00000-000000000.vg

Si el Grupo de volúmenes fue creado con más de un _PV_, habrá que realizar este
proceso con cada uno de ellos.
> Habrá que comprobar dos veces el _UUID_.

Después habrá que recuperar el _VG_ con:
    # vgcfgrestore -f /etc/lvm/archive/vg_storage_00000-000000000.vg vg_storage
> Si el _UUID_ fue el correcto, podremos comprobar con `# vgdisplay` que el
_VG_ es el adecuado.

Por último se deberán activar el/los _VG's_. Algunas veces el _LVM_ recupera los
_VG's_ pero los marca como inactivos. Para alterar su estado puede utilizarse:
    # vgchange -a y vg_storage

#### Siguiendo con el tema, antes de ascender a oficial, al sujeto de prueba.

Con la [técnica del oficial de derrota][], se pretendía hacer uso de las copias
de seguridad y su posterior recuperación, sobre un dispositivo multimedia.
Es decir un disco tipo _USB_.

personalmente considero que por cuestiones de seguridad, no deberían utilizarse
este tipo de medios, de igual forma a cómo lo haríamos con un disco mecánico sea
externo o interno.

Hay varias cuestiones a tener en cuenta. La primera de ellas, es que como se
trata de un dispositivo basado en tecnología _Flash_ la manera en la que se
accede al disco; esto es _lectura/escritura_, es sensiblemente distinta con respecto
a un disco mecánico.

Este tipo de dispositivos, es habitual encontrarlos en equipos domésticos; son
baratos, rápidos y su instalación es muy sencilla. Sin embargo, No es la mejor
forma de crear una copia de seguridad. Estando en una empresa, esto no se nos
pasaría siquiera por la cabeza!

Así que a la hora de instalar el sistema operativo, en lugar de dar el espacio libre
del disco _USB_ al _LVM_, para que este lo administre; en TerritorioLinux, hemos
separado todo el espacio de disco en su própio _LVM_. ¿Por qué? pues por que es
un peligro. Sin entrar en demasiado detalle técnico, como digimos líneas arriba,
la _velocidad_ de acceso al disco es distinta y, la probabilidad de que
suceda un error físico, en la superficie del disco, es proporcional al _precio_
del dispositivo y al uso extensivo que se haga de él.
Es decir, _Bueno, bonito, barato, sólo durante un rato!_
