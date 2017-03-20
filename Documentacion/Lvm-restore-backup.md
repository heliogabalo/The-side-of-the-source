## Restaurar backups dentro del _LVM_.






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
