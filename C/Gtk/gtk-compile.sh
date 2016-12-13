#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gcc `pkg-config --cflags gtk+-3.0` -o $aplication $fuente \
  `pkg-config --libs gtk+-3.0`
else
  echo "you have misspelled the name of the source-file!"
fi
