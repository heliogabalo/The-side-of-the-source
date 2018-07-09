## El núcleo

####	INDICE

1. [Elección del software](#i1)
2. [Construccion e instalación del _kernel_ ](#i2)
3. [Reconfiguración en caliente; con el sistema en funcionamiento](#i3)
4. [Construir un kernel de uso general](#i4)
5. [Opciones de depuración](#i5)
6. [Referencias](#i6)

---

Lo primero habrá que identificar la fuente con la que trabajar. Hay varias formas de  
hacerlo. La mas simple es ir al sitio del software en cuestión y hacer click en el  
enlace, nada nuevo hasta aquí.  

Pero si tenemos espacio en el disco, y nos apetece trastear un rato con `git`, este es  
un buen momento para instalarlo.  


#### < a name="i1">Elección del software</a>

- Descarga del núcleo:  

		git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
		cd linux-stable
		
		git tag -l | less
		
		git checkout -b stable tag


#### < a name="i2">Construcción e instalación del _kernel_</a>

Si las fuentes se descargaron, por medio  de un archivo comprimido, deberemos  
utilizar la aplicación para descomprimir el archivo.  
Si en su lugar, fueron descargadas, por medio de un _DVCS(como git)_, este paso  
anterior no sera necesario. Pero deberá planificarse donde se va a instalar el nuevo  
kernel.  

Podría darse el caso, que el nuevo  _kernel_ que pretendemos prepar fuése para  
otra máaquina, o varias máquinas, distintas de la que estamos trabajando.  

- En otra máquina:  

En este caso concreto, conviene separar el codigo resultante de la compilación,  
puesto que _podría_ hacernos falta, si se volviése a compilar el núcleo.  
En cualquier caso, como hemos decidido que el nuevo _kernel_ __no es__, para  
nuestra máquina, evitaremos mezclar directorios con nuevos módulos compilados y  
demás.  

Para ello se utilizara lo opción _output/dir_, su nomenclatura es la siguiente:  

		make O=output/dir
		
		$ make O=/mi/ruta/absoluta
		$ make O=/home/name/build/kernel menuconfig\
		$ make O=/home/name/build/kernel
		$ make O=/home/name/build/kernel modules_install install

De ésta forma, en lugar de construir hacia la ruta por defecto del sistema `/`,  
será indicada una ruta alternativa, `/home/name/build/kernel`, en este caso.  


También existe la posibilidad de crear una imagen ISO:  

		$ make -j8 isoimage


>> __nota:__ si utilizamos la opción O=/output/dir, deberemos utilizarlo todas  
>> las veces que lo invoquemos:  
		

- En el mismo equipo  

> __nota:__ recuerda que para cambiar a una rama `checkout master` y, para  
> _cambiar_ a una rama en particular, deberemos escribir todo el nombre de  
> la etiqueta ejem. `git checkout -b stable v2.6.1`. El tag __`v2.6.1`__.  


- parches, gestión, etc  
	- aplicar o revertir cambios.	 
- DVCS? como vamos a descargar la fuente  
- configuración, construcción e instalación  
	- instalación en el dom0  
	- Reconfiguración en caliente; con el sistema en funcionamiento.  
	- reconfiguración por medio de archivos `conf`  
	- Configuración con ncurses	 
	- hay otras, desde la consola debe poder hacerse  
- creacion imagen(paquete).  


#### < a name="i3">Reconfiguración en caliente; con el sistema en funcionamiento</a>

Si el _kernel_ esta configurado para ello:  
		cat /proc/config.gz | gunzip > myConfig

... una vez terminado, se puede utilizar la siguiente instrución para  
guardar el archivo de configuración fuera del _nombre_ que usará el  
sistema para `.config`.  

		make savedefconfig

		
#### < a name="i4">Construir un kernel de uso general</a>

Construye un `kernel` _por defecto_.  

		make defconfig
		
---

#### < a name="i5">Opciones de depuración</a>

En ambos casos, es una mala idea tomar por defecto las siguientes prácticas. AVISO.  
- Mantener una copia del `.config` con el que se compiló el núcleo.  
- Activar la característica `General Setup -> kernel .config support`.  
		$ cat /proc/config.gz | gunzip > /tmp/running.config
		or ...
		$ 2cat /proc/config.gz > /tmp/running.config

Ésta práctica únicamente es recomendable cuando se depura el núcleo. Es la excepción,  
ya que es cuando resulta útil. Pero no hay que olvidar desactivar la característica  
y borrar cualquier rastro de tal archivo. ¿Por qué? lol, pues por que si algo/alguien  
accede al equipo con privilegios suficientes podrá, replicar el núcleo del sistema.  
> __nota:__ siempre y cuando el sujeto tenga la capacidad, los drivers y dispositivos  
> o en su defecto, una máquina capaz de emular dichos componentes!
  
---

#### < a name="i6">Referencias</a>

[https://docs.fedoraproject.org/f26/install-guide]:[Fedora Installation Guide]
[https://en.wikibooks.org/wiki/How_To_Backup_Operating_Systems]:[How_To_Backup_Operating_Systems]
[https://www.kernel.org/doc]:[kernel-docs]
#### Reconstruir el kernel
[https://boot.fedoraproject.org/downloads]:[Reconstruir?]
#### DOWNLOAD
[https://dl.fedoraproject.org/pub/alt/bfo/bfo.iso]:[Downloads]
#### net isntall
[http://ipxe.org]:[Net-install]
