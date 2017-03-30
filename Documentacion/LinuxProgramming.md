## Programación en Linux

#### Uso del compilador de C

  - __Herramientas útiles__
    - nm: lista los símbolos en un archivo de objetos.
    - ranlib: genera un índice de contenido de un archivo y lo guarda en el mismo.
    - `-l`: _ele minúscula_, es la abreviación para el enlazador
    del compilador. Puede ser usado para enlazar la _librería_.
    Su sintaxis es la siguiente `<-l><librería>` sin espacios y
    en minúscula; ejem. `-lm` .
    > lm es libm.a, la librería estática de mates. `libm.a/libm.so` no es una librería estandard, aunque pueda pensarse lo contrario.

    - `-L`: esta opción de línea, es usada para especificar una ruta(absoluta) a una librería fuera de las rutas habituales; ejem. librerías de usuario(miLibrería.so)`<-L></path/to>` nuevamente, sin espacios y en mayúscula `-L/home/myLib.so`.

    - `ld`: cargador dinámico(dynamic loader).
    - `lsb`: Linux Standard Base.
    - `ldd`: presenta las librerías requeridas por el programa. Su sintaxis es: `<ldd> <programa>`.

#### Uso del depurador
`GDB` es la navaja suiza del programador, _El depurador_. Voy a dejarme aquí un
apunte a un pequeño script que yo uso para arrancar el programa, dentro del
depurador, y no estar repitiendo lo mismo sobre la cónsola, una y otra vez:

No tiene mucho sentido hacer un tuto aquí, por que la red tiene más _tutos_ sobre
`gdb` que _chinos_, la playa de _china gorda_.
> mirar en el directorio Xcb
