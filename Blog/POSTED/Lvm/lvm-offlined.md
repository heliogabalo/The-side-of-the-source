## Apagado de Lvm

Apagado offline o desactivación...


lvchange -an <lvpath>
vgchange -an <vgname>

If you also want to remove the device maps you can use

dmsetup ls
dmsetup remove <name>
