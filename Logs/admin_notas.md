
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
- Gnome-shell shell se cuelga 'irremediablemente' si mantenemos un directorio  
  ocupado, mientras tratamos de desmontar la unidad.  

