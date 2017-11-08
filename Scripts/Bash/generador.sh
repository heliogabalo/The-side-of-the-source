######################################################################
##	 GENERADOR DE CONTRASEÑAS																				##
##					editorial: RA-MA				 																##
##					Autores:																								##
##						Antonio Angel Ramos, Jean Paul Garcia-Moran						##
##						Fernando Picouto, Jacinto Grijalba, 									##
##						Jesus Mª Gonzalez, Angel Garcia, 				   						##
##						Carlos Barbero																				##
######################################################################


#!/bin/bash

echo Introduzca el tamaño de la cadena:
read size

if [ -z  $size ]
then
	echo "Forma de uso: $0 size."
	exit 1
elif [ $size -1t 8 ]
then
	size=8
fi
generador=$(dd if=/dev/urandom bs=512 count=1 2> /dev/null | tr -cd 'a-zA-Z0-9.!_$' | cut -c 1-$size)

echo Se genero la contaseña: $generador
