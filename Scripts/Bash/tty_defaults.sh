#!/bin/sh

## En ocasiones podemos ejecutar algo en el terminal, que pueda provocar 
## símbolos extraños en la terminal. Este pequeño script, restaura los 
## valores por defecto.

echo -e \\033c

## otra forma de restaurar la terminal es mandándo la señal directamente 
## desde el teclado ESC - c
