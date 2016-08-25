#!/bin/sh
path=/home/heliogabalo/Github/heliogabalo.github.io/Trash
dest=/home/heliogabalo/Github/heliogabalo.github.io/TerritorioLinux

markdown $path/qemu_notas.md > $path/qemu_notas.html \
  && sed -i '64r $path/qemu_notas.html' $dest/qemu_doc.html
