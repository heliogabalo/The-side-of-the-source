#!/usr/bin

# Utilidad para buscar paquetes debian comprimidos
# en un determinado formato. Ver man debootstrap

path=/usr/sbin

$path/debootstrap --download-only sid sid-root-path
cd sid-root-path

find -name *.deb |while read deb;do \
  if ar t $deb |grep -q data\.tar\.$COMP;then \
    echo $deb; \
  fi \
done |sort
