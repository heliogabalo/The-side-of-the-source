#!/bin/sh

#  qemu-system-i386 test01.img -enable-kvm -net nic,model=rtl1839 -net user -m 2047 &
#  -net user,id=mynet0,net=111.118.9.2/24,dhcpstart=111.118.9.8 \

qemu-system-x86_64 -hda /mnt/usr/rhel.qcow2 \
	-cdrom /tmp/rhel-server-7.4-x86_64-boot.iso \
  -net nic,model=rtl8139 \
  -net user,id=bridge0,net=111.118.9.2/24,dhcpstart=111.118.9.8 \
  -m 2047 &

