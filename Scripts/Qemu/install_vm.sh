#!/bin/sh

qemu-system-i386 -hda buffing_winXP.raw \
  -net nic,model=rtl8139 \
  -net user,id=mynet0,net=111.118.9.2/24,dhcpstart=111.118.9.8 \
  -net macaddr=52:54:A5:BF:3A:15 \
  -cdrom winXPsotaboloD.iso -boot cd -m 2047 &



#  qemu-system-i386 test01.img -enable-kvm -net nic,model=rtl1839 -net user -m 2047 &


qemu-system-i386  /mnt/iso-images/bfo.iso \
	-hda net-istall.raw \
  -net nic,model=rtl8139 \
  -net user,id=mynet0,net=111.118.9.2/24,dhcpstart=111.118.9.8 \
  -net macaddr=52:54:A5:BF:3A:15 \
  -m 2047 &
