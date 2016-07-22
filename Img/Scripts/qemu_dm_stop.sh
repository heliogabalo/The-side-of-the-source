#!/bin/sh

umount /media/heliogabalo/Windows/winXPsataDSP3.iso
qemu-nbd -d /dev/nbd0
rmmod -v nbd
