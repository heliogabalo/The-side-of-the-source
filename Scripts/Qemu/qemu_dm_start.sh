#!/bin/sh

modprobe nbd max_part=16  
qemu-nbd -c /dev/nbd0 /my/path/to/backing_files/win_a_chopa.iso
partprobe /dev/nbd0 
mount /dev/nbd0p1 /my/path/to/backing_files/Mnt/win_a_choppa.iso
