Aqui enlazan otras paginas:

Lo primero habra que identificar la fuente con la que trabajar. Hay varias formas de
hacerlo. La mas simple es ir al sitio del software en cuestion y hacer click en el 
enlace, nada nuevo hasta aqui.

Pero si tenemos espacio en el disco, y nos apetece trastear un rato con `git`, este es
un buen momento para instalarlo.

#### Eleccion del software

		git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
		cd linux-stable
		
		git tag -l | less
		
		git checkout -b stable tag

#### Construccion e instalacion del _kernel_

Si las fuentes se descargaron, por medio  de un archivo comprimido, deberemos
utilizar la aplicacion para descomprimir el archivo.
Si en su lugar, fueron descargadas, por medio de un _DVCS(como git)_, este paso 
anterior no sera necesario. Pero debera planificarse donde se va a instalar el nuevo
kernel.

Podria darse el caso, que el nuevo  _kernel_ que pretendemos prepar fuese para 
otra maquina, o varias maquinas, distintas de la que estamos trabajando.

- En otra maquina

En este caso concreto, conviene separar el codigo resultante de la compilacion,
puesto que _podria_ hacernos falta, si se volviese a compilar el nucleo.
En cualquier caso, como hemos decidido que el nuevo _kernel_ __no es__, para
nuestra maquina, evitaremos mezclar directorios con nuevos modulos compilados y
demas.

Para ello se utilizara lo opcion _output/dir_, su nomenclatura es la siguiente:

		make O=output/dir
		
		$ make O=/mi/ruta/absoluta
		$ make O=/home/name/build/kernel menuconfig\
		$ make O=/home/name/build/kernel
		$ make O=/home/name/build/kernel modules_install install


De esta forma, en lugar de construir hacia la ruta por defecto del sistema `/`,
sera indicada una ruta alternativa, `/home/name/build/kernel`, en este caso.


Tambien existe la posibilidad de crear una imagen ISO:

		$ make -j8 isoimage


> __nota:__ si utilizamos la opcion O=/output/dir, deberemos utilizarlo todas
> las veces que lo invoquemos:
		

- En el mismo equipo

################# BORRAR ESTO ####################

Parece que todo es muy confuso, pero piensa un momento, de verdad quieres crear
un sistema operativo desde ceso? entiendes que eso conyeva la seleccion de todas
las aplicaciones y su testeo de compatibilidad?

No, esa no es la forma. Hay que instalar la distribucion y despues modificar el kernel,
de lo contrario estariamos hablando de un proyecto que puede durar _$(indeterminado)_.
El jaleo mental, es que pretendo hacer las pruebas en una _VM_ por eso todo este rollo,
de la imagen, el directorio y demas. Necesito un campo de prueba donde si se incendia
algo, pueda salir corriendo sin mirar atras y, borrar el fuego si procede!

Lo primero sera conseguir la imagen, el sistema. Puede ser el mismo disco de instalacion
o generar una imagen desde la que se pueda arrancar, esto implica al menos un sistema
de ficheros donde montar la imagen del kernel.

Decidir despues si lo hacemos con _Qemu_ o no.

Si lo hacemos con Xen, hay que reconfigurar el kernel e instalar Xen, despues crear
la MV.

Si lo hacemos con Qemo, ejem, para ver si funciona o no la reconfiguracion del 
kernel, goto line 1.

################# END BORRAR ESTO ####################

> __nota:__ recuerda que para cambiar a una rama `checkout master` y, para
> _cambiar_ a una rama en particular, deberemos escribir todo el nombre de 
> la etiqueta ejem. `git checkout -b stable v2.6.1`. El tag __`v2.6.1`__.


- parches, gestion, etc
	- aplicar o revertir cambios.	
- DVCS? como vamos a descargar la fuente
- configuracion, construccion e instalacion
	- instalacion en el dom0
		- Reconfiguracion en caliente; con el sistema en funcionamiento.		
		- reconfiguracion por medio de archivos `conf` 
		- Configuracion con ncurses		 
		- hay otras, desde la consola debe poder hacerse
- creacion imagen(paquete).





#### Reconfiguracion en caliente; con el sistema en funcionamiento.

Si el _kernel_ esta configurado para ello:
		cat /proc/config.gz | gunzip | less

... una vez terminado, se puede utilizar la siguiente instrucion para
guardar el archivo de configuracion fuera del _nombre_ que usara el
sistema para `.config`.

		make savedefconfig
		
#### Construir un kernel de uso general

Construye un `kernel` _por defecto_.

		make defconfig
