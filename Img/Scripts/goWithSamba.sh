#!/bin/sh

qemu-system-i386 $my_path/Overlays/teta_over.qcow2 \
  -net nic,model=rtl8139,vlan=22 \
  -net user,vlan=22,smb=/media/heliogabalo/Windows/Mnt \
  -m 2047 & 