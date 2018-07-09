[Introducción](#i1)
[Referencias](#i2)

## Herramientas de depuración del _kernel_ ##

#### [Introducción](i1) ####

![Main Menu](images/Blog/nCurserMenu.png "nCursesMenu")

Ajustamos el tamaño de la _cónsola_, para que la librería `ncurses` pueda construir el menú sin problema.

Lo primero será echarle un ojo al menú de configuarción y, comprobar con qué variables vamos a trabajar. También podemos consultar el _archivo de llaves_, aplicando ciertos filtros, para evitar constuir el _menú_ y agilizar el proceso.

		cat .config | grep IKCONFIG

![Grep filter](images/Blog/checkVar.png "bashShell")
		
Puede verse que la variable está desctivada. Habrá que activarla. 

> NAVEGACIÓN BÁSICA
> 
> La fomara en que nos movemos por el menú, es bastante simple; en cualquier momento podemos consultar la lista de opciones disponibles, situadas en el _cuadro de leyenda_, que reza justo debajo de la lista de variables.
> Ayuda: tecla `?` o `H`
> Seleccionar: `return/enter`
> Salir: `E`
> Guardar: `S`
> Cargar: `L`
> --- ARRIBA ---
> Módulo: `M` 
> Cómo parte del _kernel_: `Y`
> Desactivado: `N` -> `[]`
> Con las teclas de dirección, nos movemos por la lista.

Planteamos la lista de variables con las que trabajaremos, navegando hasta ellas para familizarizarnos con el entorno...

* - `CONFIG_IKCONFIG`
* - `CONFIG_KALLSYMS`
* - `CONFIG_X86_MCE`
* - `CONFIG_ACPI_DEBUGGER`
* - `CONFIG_ACPI_DEBUGGER_USER`

Por ejemplo, `CONFIG_X86_MCE`, desde el menú principal `ncurses`, pulsamos la _barra avanzada_ `/`, para buscar la referencia hacia la variable. El menú explica que `X86_MCE` está activada y fué construida la característica, como parte del kernel.

![Description KeyVariable](images/Blog/x86_mce.png "nCursesMenu")

- Detalle de la _cadena_ untilizada: `X86_MCE`.
- Tipo de variable boleana, `bool`.
- Descripción resumida, de la varible `prompt`. En este caso se trata de `comprovación de máquina/ reporte por sobrecalentamiento` (Machine check / overheating reporting).
- La localicación anidada en el _árbol_, para la lista de variables. `(1)` hace referencia al _primer nivel_ en el que es sitúada la varible. Sección `Tipo y características del procesador`(Processor type and features).

Navegamos hasta dicha sección, `Main -> Processor type and features` y situando el selector sobre dicha sección; leemos la ayuda descriptiva, `H`.

![Description KeyVariable](images/Blog/x86_mceHelp.png "nCursesMenu")

Hemos aprendido cómo movernos por el menú, consultar la información relativa y, la ayuda disponible.

Volvemos a leer nuestra lista de variables. El primer paso es volver al `main` y, situarnos sobre `G` -> _enter_ sobre `General setup` -> `K` _enter_ sobre `kernel compression mode (gzip)` -por defecto, está seleccionado el formato de compresión de archivo tipo `gzip`, podemos cambiarlo situando el selector sobre el formato adecuado y, pulsando la barra espaciadora, lo que nos devolverá al menú anterior. Pero esta no es la variable que queremos cambiar, este es el programa que utilizará el _kernel_ para comprimir la imagen del kernel cuando lo construyamos, y el mismo formato de _descompresión_, durante el arranque del sistema y, carga de la imagen del kernel en la `ram`.

Sale fuera de lo que pretendíamos hacer, pero me viene bien para explicar que nuestro entorno de trabajo `ncurses`, tiene sus _problemillas_; es una _joya en bruto_, con sus asperezas y particularidades própias. Al pulsar la tecla `K` repetídamente, deberíamos poder navegar entre la lista de _entradas_ en el menú, que empiezan por la letra `K`, hay varias. Pero en lugar de esto, el selector se sitúa invariablemente sobre la entrada `Kernel compression mode (Gzip)`.

Vale, pulsamos _avanzar página_ hasta perder de vista la entrada. Ahorar sí, navegamos con la tecla `K` sobre la lista de entradas comenzando por dicha letra.

Activaremos la variable con la letra `Y` -de _yes_. También la opción que aparece tras activar la opción. `activar acceso al .config através de /proc/config.gz (NEW)` (Enable acces to .config through /proc/config.gz).

Activamos esta segunda opción, para poder evitar el tener que extraer del própio kernel, el archivo de configuración, mediante un `script`. Así podremos consultar la _lista_ desde `/proc`, descomprimiendo posteriormente el archivo.

... y guardamos. ¿Con qué nombre queremos guardar el archivo? le damos a `OK`, para guardar sin cambiar el nombre de éste. Mencionar aquí, que este es el archivo de configuración, con el que construiremos nuestro nuevo kernel. No es el nombre del archivo, que generará la construción del kernel. Este último siempre tendrá el mismo nombre y será guardado bajo `/proc/`. 

Esto es una maravilla, por que podemos trastear con distintas configuraciones e ir guardando las "plantillas" con distintos nombres, hasta dar con la configuración adecuada!

Por ejemplo, imaginemos que `ACPI` nos da problemas, que empieza a cargar historias, haciendo referencias a dispositivos que nuestro _ordenata_ ni tiene. Prueba y efecto...

La cosa se alarga y no quiero escribir una práctica _kilométrica_. Lo dejo aquí, para revisar con más tiempo y calma, las varibles necesarias para construir el depurador. Hasta la próxima.

#### < a name="i2">Referencias</a> ####

[https://docs.fedoraproject.org/f26/install-guide]:[Fedora Installation Guide]
[https://en.wikibooks.org/wiki/How_To_Backup_Operating_Systems]:[How_To_Backup_Operating_Systems]
[https://www.kernel.org/doc]:[kernel-docs]
#### Reconstruir el kernel
[https://boot.fedoraproject.org/downloads]:[Reconstruir?]
#### DOWNLOAD
[https://dl.fedoraproject.org/pub/alt/bfo/bfo.iso]:[Downloads]
#### net isntall
[http://ipxe.org]:[Net-install]
