#!/bin/sh

qemu-system-i386 -hda backing_winXP.raw \
  -net nic,model=rtl8139 \
  -net user,id=helionet0,net=192.168.0.8/24,dhcpstart=192.168.0.8 \
  -net macaddr=52:54:15:6F:91:A3 \
  -cdrom winXPsataD.iso -boot cd -m 2047 &



#  qemu-system-i386 test01.img -enable-kvm -net nic,model=rtl1839 -net user -m 2047 &
