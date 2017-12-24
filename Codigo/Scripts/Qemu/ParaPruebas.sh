#!/bin/sh

#  qemu-system-i386 test01.img -enable-kvm -net nic,model=rtl1839 -net user -m 2047 &
#  -net user,id=mynet0,net=111.118.9.2/24,dhcpstart=111.118.9.8 \

qemu-system-x86_64 -hda /mnt/usr/firtsCowInstall.qcow2 \
	-cdrom /tmp/tails-amd64-3.3.iso \
  -net nic,model=rtl8139 \
  -m 2047 &




