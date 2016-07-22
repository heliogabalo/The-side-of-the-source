#!/bin/sh

path=/media/heliogabalo/Windows/BackingFiles/

qemu-img create -o backing_file=$path/my_backin_cacawinXP.raw,backing_fmt=raw \
  -f qcow2 $path/Overlays/cacawinback.cow
