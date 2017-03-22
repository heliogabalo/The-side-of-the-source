#!/bin/sh

virt-install \
--name fedora24 \
--ram 4096 \
--disk path=/var/lib/libvirt/images/fedora24.img,size=30 \
--vcpus 2 \
--os-type linux \
--os-variant fedora23 \
--network bridge=br0 \
--graphics none \
--console pty,target_type=serial \
--location 'http://ftp.jaist.ac.jp/pub/Linux/Fedora/releases/24/Server/x86_64/os/' \
--extra-args 'console=ttyS0,115200n8 serial'
