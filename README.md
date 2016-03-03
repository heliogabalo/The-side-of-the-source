# The-side-of-the-source #
##...a deep hole on the side source. ##

Este repositorio contiene código escrito en distintos lenguajes de programación.
Es nada más que un espacio donde almacenar archivos interesentes, obtenidos de
distintas fuentes.

Algunos archivos son más dependientes que otros, aunque en general, pueden ser
compilados como aplicaciones independientes.

Para compilar código fuente escrito en C/C++ :

ejem.

> $gcc -o objeto source linker

  objeto - será el binario ejecutable.

  source - código fuente(nuestro archivo).

  linker - librería a enlazar. Para enlazar NCURSES: -lncurses

La mayoría son portables, aunque sí es cierto que algunas librerías son dependientes.
Cualquier aclaración/aportación/mejora será más que bienvenida.

Aquellos archivos con _prefijo_ + _ pueden ser compilados como grupo, para lo que 
aconsejo el uso de un Makefile. 
En el caso de un IDE, indicarlo al linker. No puedo añadir mas a esto, pues no 
me gustan los IDEs y no trabajo con ellos.

Turorial Makefile: http://mrbook.org/blog/tutorials/make/

Hay que tener en cuenta que los "make" casi son un lenguaje en sí mismos, por lo que
la indenteción, es MUY IMPORTANTE, o no compilará.



*    TODO 

      - README.md in english.
      - [x] función exec - function 
      - función login - function
      - función stty - function
      - Menú functional - cusrse_menu
      - Paneles - curse_pane
      - Ventanas - curse_win
      - función check - function. Comprueba tipo tty.
      - función grub - UEFI nuevo estilo. Nuevo entre comillas *"algo aquí"*.
      - Integración de artículos en la web: 
      - linux4free - function
      - SVGA/VGA/EGA/CGA - function
      - check_arch - function 
      - controlador frontend - via emacs(lisp scheme-guile)
      - mapa de red
      



