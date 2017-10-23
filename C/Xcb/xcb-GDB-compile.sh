#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gdb --args \
  gcc -g `pkg-config --cflags x11 --cflags xcb-atom` -o $aplication $fuente \
  `pkg-config --libs xcb` `pkg-config --libs x11` `pkg-config --libs xcb-atom`
else
  echo "you have misspelled the name of the source-file!"
fi
