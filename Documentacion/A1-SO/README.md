## El nucleo

####	INDICE

1. Eleccion del software
2. Construccion e instalacion del _kernel_ 
3. Reconfiguracion en caliente; con el sistema en funcionamiento.
4. Construir un kernel de uso general
5. Referencias

---

Lo primero habra que identificar la fuente con la que trabajar. Hay varias formas de
hacerlo. La mas simple es ir al sitio del software en cuestion y hacer click en el 
enlace, nada nuevo hasta aqui.

Pero si tenemos espacio en el disco, y nos apetece trastear un rato con `git`, este es
un buen momento para instalarlo.

#### Eleccion del software

- Descarga del nucleo:\

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
		
		
---

## Referencias

[https://docs.fedoraproject.org/f26/install-guide]:[Fedora Installation Guide]
[https://en.wikibooks.org/wiki/How_To_Backup_Operating_Systems]:[How_To_Backup_Operating_Systems]
[https://www.kernel.org/doc]:[kernel-docs]
#### Reconstruir el kernel
[https://boot.fedoraproject.org/downloads]:[Reconstruir?]
#### DOWNLOAD
[https://dl.fedoraproject.org/pub/alt/bfo/bfo.iso]:[Downloads]
#### net isntall
[http://ipxe.org]:[Net-install]
