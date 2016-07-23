#!/bin/sh

umount /my/path/to/backing_files/winXPsotaballoDSP3.iso
qemu-nbd -d /dev/nbd0
rmmod -v nbd
