## leemos el archivo y redireccionamos la salida a traves de sed
cat logfile | sed 's/|/ /' | awk '{print $1, $8}'
