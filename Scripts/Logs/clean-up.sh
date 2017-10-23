#!/bin/bash

#Cleanup, version 2
# Insert code here to print error message and exit if not root

LOG_DIR=/var/log
# Variables are better than hard-code values
cd $LOG_DIR

cat /dev/null > messages
cat /dev/null > wtmp

echo "Logs cleaned up."

exit #la forma correcta de salirse es 
     # siempre con 'exit' sin parametros
     #+ los comandos precedentes.

