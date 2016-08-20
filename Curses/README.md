EscritorioCurse

El objeto de esta aplicación, es crear un entorno de programación, con las 
capacidades de un entorno de texto, libre de cargas de grandes librerias, 
própias de un entorno gráfico.




*   La aplicación:

        - [x] Main(). Inicializa ventana.
        - [x] Cabecera.h 
        - [x] Aislar funciones del main(). 
        - [x] Menú principal.
        - [x] Tags para VIM. ctags.
        - [x] Recolocar ventana.
        - [x] Makefile



*   TODO


        - Redimensionar ventana.
        - Paneles y paneles en segundo plano.
        - Espacio de usuario. Guardar config.
        - Aplicaciones comunes:
          -- Compiladores.
          -- Debugers.
          -- Visor de PDFs.
          -- Visor de Imágenes.
          -- Streams en general. Streams.txt.
        - "La terminal".
        - "La pts".
        - Manipulacion de sdtout(fd1) con Sed y awk.
        - Estado "POSIX" de la aplicación.
        - Acerca de OpenGL.txt.
        - Acerca de Frame Buffer.txt.
        - Entorno seguro. Shell cookeada. Modo restringido.
        - Etags. Usuarios Emacs.



  Para comilar: 
  <pre><code>
    $cd Curses
    $make
    $make clean
    //make clean borra los archivos objeto.
  </pre></code>


  Advertencia: La aplicación está escrita en C, sin usar mas librerías
  que las proias del lenguaje y Ncurses. Esta última, está ámpliamente
  integrada en las plataformas más comunes. No debería suponer ningún
  problema su compilación.
  De cualquier forma únicamente ha sido probada en la cónsola de linux
  Esto es, Bash y Zsh. 


  N.T.d.A: Esta aplicación está basada en fuentes de código abierto.
  Gracias de antemano, a todos aquellos que en su día compartieron el
  "source".


Indice antiguo (copiado aquí sólo como seguimiento)
Los archivos relacionados con la interface_proyect de Ncurses, están bajo el
directorio Curses. Otros que estaban en el root, han sido mividos al directorio
`C` como archivos sueltos(Lenguaje C).

*  TODO

      - README.md in english.  
      - [x] función exec - function  
      - [x] función login - function  
      - función stty - function  
      - [x]Menú functional - cusrse_menu  
      - Paneles - curse_pane  
      - [x] Ventanas - curse_win  
      - Directorio Curses. Readme_curses.txt
      - función check - function. Comprueba tipo tty.
      - función grub - UEFI nuevo estilo. Nuevo entre comillas *"algo aquí"*.
      - Integración de artículos en la web:
      - linux4free - function
      - SVGA/VGA/EGA/CGA - function
      - check_arch - function
      - controlador frontend - via emacs(lisp scheme-guile)
      - mapa de red






