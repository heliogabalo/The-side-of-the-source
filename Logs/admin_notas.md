
- Diversas herramientas registran distintas lecturas de memoria.  
  Esto parece indicar un residente Free!.  

  ~~~  
  1  [||||||----------------------------------------------------------------------6.0%]   
  2  [|||||-----------------------------------------------------------------------4.6%]   
  Mem[|||||||||||||||||||||||||||||||||||||||-------------------------------709M/3.95G]   
  Swp[                                                                        0K/8658M]   

  Tasks: 114, 190 thr; 1 running  
  Load average: 0.35 0.92 0.81  
  Hostname: NR021AA  
  Avg[|||||                                                                       5.6%]  
  ~~~  
Desde la línea de comandos:  

  ~~~  
                 total       used       free     shared    buffers     cached  
  Mem:          4042       1904       2138         11        130       1012  
  -/+ buffers/cache:        760       3282  
  
 ~~~  
> Se ve claramente que la lectura de los totales interpretados por el sistema  
> difiere, de una aplicación a otra.

- La ejecución sobre shell, arrastra el binario, en el arbol de procesos,  
  durante la carga en el sistema. (aleatoriOh???)  
  ~~~  
$ ps
  PID TTY          TIME CMD
10470 pts/1    00:00:00 bash
10723 pts/1    00:00:00 ps
  ~~~  
... cuando se está lanzando la aplicación mediante `exec`  
  ~~~  
tmux
6 S  0.0  0.1  0:00.15 │  ├─ su user
6 S  0.0  0.1  0:00.22 │  │  └─ bash
2 S  0.0  0.1  0:00.06 │  │     └─ bash
  ~~~   


- Gnome-shell shell se cuelga 'irremediablemente' si mantenemos un directorio  
  ocupado, mientras tratamos de desmontar la unidad.  
- He comprobado que ciertas aplicaciones de sistema, no están isntaladas. Sin 
  embargo, hay manual de referencia. Esto no parece algo normal.
  - tgkill no está instalado: se trata de una aplicación para cerrar hilos 
  selectivamente. A diferencia de kill, que mandaría una señal aleatoria sobre el  
  hilo en cuestión, cerrando el proceso principal.  
- Pongo un ejemplo de este comentario anterior: hay exploradores, que funcionan
  bastante bien sin necesidad de abrir decenas de hilos, de forma absurda e inutil.  
  Esta idea, es razonable, si pensamos que los exploradores trabajan con aplicaciones  
  externas, la cuales son las que realmente deben gestionar los _hilos_, cuando es  
  necesario. 
  Pongo otro ejemplo; es estúpido abrir 10 conexiones, para hacer una búsqueda en
  google. Seguramente habrá gente que se crea, que esto es normal. Ciertamente  
  no lo es.

