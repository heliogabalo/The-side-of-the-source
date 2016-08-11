#!/bin/sh

path1=~/Github/The-side-of-the-source/Documentacion
path2=~/Github/heliogabalo.github.io/blog/archives/Trash
$user_file
$userfile

- preguntar usuario nombre archivo md a convertir
- preguntar por nombre archivo html $userfile e indicar escribir extension.html
- comprobar archivo existe en $path1
- copiar archivo $path1/$user a $path2/basura.md
- operar con $path2/basura.md 
  - cat "<link href='txtstyle.css' rel='stylesheet' type='txt/css' />" > $userfile
  - abra que comprobar el flujo de línea, o con cat -n 1 > to $userfile(algo así)
  - convert2html $path2/basura.md $path1/$user_file
- vaciar $path2/basura.md

