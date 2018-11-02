#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gcc `pkg-config --cflags x11` -o $aplication $fuente \
  `pkg-config --libs xcb` `pkg-config --libs x11`
else
  echo "you have misspelled the name of the source-file!"
fi
