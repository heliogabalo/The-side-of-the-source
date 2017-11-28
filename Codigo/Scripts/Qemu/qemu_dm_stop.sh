#!/bin/sh

umount /my/path/to/backing_files/win_a_Punch_in_the_nose.iso
qemu-nbd -d /dev/nbd0
rmmod -v nbd
