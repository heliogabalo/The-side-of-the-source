#!/bin/sh

modprobe nbd max_part=16  
qemu-nbd -c /dev/nbd0 /media/heliogabalo/Windows/Backups/winXPsataDSP3.iso
partprobe /dev/nbd0 
mount /dev/nbd0p1 /media/heliogabalo/Windows/Mnt/winXPsataDSP3.iso
