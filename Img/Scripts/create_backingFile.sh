#!/bin/sh

path=/my/path/to/backing_files/

qemu-img create -o backing_file=$path/armery_file.raw,backing_fmt=raw \
  -f qcow2 $path/Overlays/img1.cow

