# The-side-of-the-source
##...a deep hole on the side source. ##

Este repositorio contiene código escrito en distintos lenguajes de programación.
Es nada más que un espacio donde almacenar archivos interesentes, obtenidos de
distintas fuentes.


TODO: aquí va el índice del repositorio
# Indice
1. ...
99. Reseña a proceso de compilación.
---


#### 99. Reseña a proceso de compilación.
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

Aquellos archivos con _prefijo_ + `_` pueden ser compilados como grupo, para lo que 
aconsejo el uso de un Makefile. 
En el caso de un IDE, indicarlo al linker. No puedo añadir mas a esto, pues no 
me gustan los IDEs y no trabajo con ellos.

Turorial Makefile: http://mrbook.org/blog/tutorials/make/

Hay que tener en cuenta que los "make" casi son un lenguaje en sí mismos, por lo que
la indenteción, es MUY IMPORTANTE, o no compilará.


      

Si quieres participar activamente en este repositorio tienes dos formas de hacerlo:
- jonitjuego arroba gmail.com. Mándame un email con tu clave pública para que pueda
  añadirte como colaborador.
- Puedes clonar la repo con:
  <pre><code>git clone https://github.com/heliogabalo/The-side-of-the-source.git</code></pre> 
  o hacer un fork al mismo y tabajar sobre tu propia rama.


