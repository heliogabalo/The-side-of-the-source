#!/bin/bash

echo "wich file to compile? "
read fuente
echo "name of the aplication?"
read aplication
if [ -f $fuente ]
then
  gcc -o $aplication $fuente   
else
  echo "you have misspelled the name of the source-file!"
fi
