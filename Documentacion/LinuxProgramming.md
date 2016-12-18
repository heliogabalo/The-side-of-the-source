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
