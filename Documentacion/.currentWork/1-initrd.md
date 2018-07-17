[Utilizando el disco de RAM inicial(`initrd`)](#i1)

[Referencias y agradecimientos](#i99)

### Utilizando el disco de RAM inicial(`initrd`) ###

Escrito por __Werner Almsberger__ en 1996,2000 <werner.almesberger@epfl.ch> y Hans Lermen <lermen@fgan.de>

`initrd` proporciona la capacidad de cargar un disco RAM, por el cargador de arranque.
Éste disco, podrá ser montado como FS raíz, sobre el que podrán correr otros programas. Después de todo, un nuevo FS podrá ser montado desde un distinto dispositivo. El ráiz anteior -desde initrd, es entonces movido a un directorio y, podrá ser subsiguientemente, desmontado.















### <a name="i99">Referencias y agradecimientos</a> ###


