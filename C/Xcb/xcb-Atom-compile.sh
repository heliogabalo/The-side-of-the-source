#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gcc `pkg-config --cflags xcb-atom` -o $aplication $fuente \
  `pkg-config --libs xcb-atom` 
else
  echo "you have misspelled the name of the source-file!"
fi
