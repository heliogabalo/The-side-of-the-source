#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gdb --args \
  gcc -g `pkg-config --cflags x11` -o $aplication $fuente \
  `pkg-config --libs xcb` `pkg-config --libs x11`
else
  echo "you have misspelled the name of the source-file!"
fi
