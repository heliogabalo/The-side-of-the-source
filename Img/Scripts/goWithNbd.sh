#!/bin/sh

my_path=/black/star/BackingFiles

qemu-system-i386 \
  -net nic,model=rtl8139,vlan=22 \
  -net user,vlan=22 \
  -object tls-creds-x509,id=tls0,dir=$HOME/.pki/qemutls,endpoint=client \
  -drive driver=nbd,host=localhost,port=10809,tls-creds=tls0 \
  $my_path/Overlays/imginatelo.cow
