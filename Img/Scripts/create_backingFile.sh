#!/bin/sh

path=/media/heliogabalo/Windows/BackingFiles/

qemu-img create -o backing_file=$path/image_file.raw,backing_fmt=raw \
  -f qcow2 $path/Overlays/img1.cow

