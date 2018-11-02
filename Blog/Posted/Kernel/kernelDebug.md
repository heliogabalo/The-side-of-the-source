## El kernel

####	INDICE

1. [Elección del software](#i1)
2. [Construccion e instalación del _kernel_ ](#i2)
3. [Reconfiguración en caliente; con el sistema en funcionamiento](#i3)
4. [Construir un kernel de uso general](#i4)
5. [Opciones de depuración](#i5)
6. [Referencias](#i6)

---

Esta semana empezamos una serie de artículos, dedicados al kernel. Como es un tema complejo y extenso, será dividido en distintas entregas. 
Cuando el artículo esté completo, será habilitado un paginador, para facilitar su lectura.

Huelga decir, que al ser una _práctica_, está sujeto a cambios, en función de los resultados obtenidos... 


#### < a name="#i1">Elección del software</a>

En primer lugar, habrá que identificar la fuente con la que trabajar. Hay varias formas de hacerlo. La mas simple es ir al sitio del software en cuestión y hacer click en el enlace, nada nuevo hasta aquí. 

Pero si tenemos espacio en el disco, y nos apetece trastear un rato con `git`, este es un buen momento para instalarlo.

El repositorio _oficial_: [kernel.org](https://www.kernel.org/)

__Descarga del núcleo con un DVCS(git):__

		git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git
		cd linux-stable
		
		git tag -l | less
		
		git checkout -b stable tag

> __nota:__ recuerda que para cambiar a una rama `checkout master` y, para
> _cambiar_ a una rama en particular, deberemos escribir todo el nombre de
> la etiqueta ejem. `git checkout -b stable v2.6.1`. El tag __`v2.6.1`__.
> DVCS - Distributed Version Control System.


__Descarga del _kernel_ en formato comprimido__

Esta opción es la más rápida, ya que sólo estaremos descargando la versión del kernel con la que hayamos decidido trabajar.

Apuntamos el navegador hacia el repositorio y, damos un _click_ al archivo en cuestión.
Para descomprimir el archivo:

		xz -cd linux-4.X.tar.xz | tar xvf -


#### < a name="#i2">Construcción e instalación del _kernel_</a>

Si las fuentes se descargaron, por medio  de un archivo comprimido, deberemos utilizar la aplicación para descomprimir el archivo.
Si en su lugar, fueron descargadas, por medio de un _DVCS(como git)_, este paso anterior no sera necesario. Pero deberá planificarse donde se va a compilar el nuevo kernel. Esto es la _construcción(build)_.

__En el mismo equipo__

Son cuatro -tirando a mucho, los archivos estríctamente necesarios:

- El `initramfs`.
- La própia imagen del kernel `vmlinuz`, habitualmente.
- El `System.map`.
- El archibo de configuración `.config` en formato comprimido `/proc/config.gz`. Si es que la característica fue activada antes de la compilación.

Todo lo demás, es absolutamente innecesario; a menos que sea preciso trabajar en el código, por alguna razón. Esto quiere decir, que tras instalar y configurarar, el `boot(grub)` con la nueva imagen del kernel, podremos deshacernos del código generado y de la fuente.


__En otra máquina__

Podría darse el caso, donde el nuevo _kernel_ que pretendemos preparar fuése para otra máquina, o varias máquinas, distintas de la que estamos trabajando.

Convendrá separar el codigo resultante de la compilación, puesto que _podría_ hacernos falta, si se volviése a compilar el núcleo.
En cualquier caso, como hemos decidido que el nuevo _kernel_ __no es__, para nuestra máquina, evitaremos mezclar directorios con nuevos módulos compilados y demás.

Para ello se utilizará lo opción _output/dir_, su nomenclatura es la siguiente:

		make O=output/dir
		
En primer lugar, cambiaremos al directorio donde será generado el código para el nuevo _kernel_. 

		cd /usr/src/linux-4.X

		$ make O=/mi/ruta/absoluta
		$ make O=/home/name/build/kernel menuconfig\
		$ make O=/home/name/build/kernel
		$ make O=/home/name/build/kernel modules_install install

> __nota:__ si utilizamos la opción O=/output/dir, deberemos utilizarlo todas
> las veces que lo invoquemos(el `make`):


De ésta forma, en lugar de construir hacia la ruta por defecto del sistema `/$currentPath`, será indicada la ruta donde se encuentra la fuente, `/home/name/build/kernel`, en este caso.

warning:
Nótese que primero hemos descargado la fuente, sobre un directorio donde tengamos los suficientes permisos -para _no andar trastreando_, hasta el momento de la instalación.
Esto significa que la salida de código generada por el compilador, sucede en el directorio __donde nos encontremos__!!.
Si al construir(to build) no cambiamos al directorio "objetivo", el código resultante se _mezclará_ con el de la fuente!!.

En el momento de escribir este "Cómo funciona", leo una nota sobre el directorio `/usr/src` que advierte el evitar su uso, debido a que el propio _SO_ lo utiliza para _las cabeceras del kernel_. En otro momento explicaré que son, y como las utiliza el _SO_. 
Por cierto, si se busca en la documentación de la distribución instalada, es fácil encontrar alguna suerte de tutorial, utilizando las propias herramientas del sistema, para actualizar el kernel -`apt, dnf, yum ...`. El método que utilizaremos aquí, es _en modo dificil_, usease, ensuciándonos las manos, y _destripando_ el kernel, su configuración, etc.

__Así o asá__

Alguno ya está clamando al cielo por que desde `/usr/src`, no tiene acceso su _usuario_.
Pero esto es muy fácil de resolver...

		$ cd /usr/
		# mkdir misRepos
		# chown meYo:meYo misRepos
		$ cd /usr/misRepos
		$ mkdir linux-version-X
		
... a lo bruto.

Como vamos a _exponer_ el código fuente, en lugar de trabajar sobre `/usr`, lo que vamos a hacer es crear un directorio de construcción, en nuestro espacio de usuario. Separándolo de la fuente...

		$ mkdir /home/user/build

Los más preocupados con la seguridad y buenas prácticas de administración, obviamente lo harán _asá_ ...

		# mv /tmp/linux-version-descargada /usr/src
		y descomprimimos.

Aunque habrá que habilitar los permisos de usuario de todas formas, si es que el directoriorio confina al adminitrador aquí. Por lo que este método habrá que investigarlo a fondo. MITO.

warning
Se hace saber, que el ordenador NUNCA BORRA, un archivo; lo quita del _registro_. Por lo que, aquel que se haya equivocado -en `kb, mb, gb...`, y los temas de analisis forense le resbalen como el _tocino_, recomiendo una pronta descarga, equivalente al tamaño del _error_, con objeto de actualizar/sobreescribir el _registro_.
La alternativa es __escribir__ el espacio utilizado a `bit 0`. En linux utilizamos `shred` para esto.

En realidad, aquí se abre un extenso debate, sobre prácticas de seguridad de sistema, quedando fuera de _ámbito_, del presente documento. [Link a lol](http://territoriolinux.net).


#### < a name="#i3">Reconfiguración en caliente; con el sistema en funcionamiento</a>

Si el _kernel_ esta configurado para ello:  
		cat /proc/config.gz | gunzip > myConfig

... una vez terminado, se puede utilizar la siguiente instrución para guardar el archivo de configuración fuera del _nombre_ que usará el sistema para `.config`. 

		make savedefconfig .myConfig

		
#### < a name="#i4">Construir un kernel de uso general</a>

Construye un kernel _por defecto_. 

		make defconfig

Esta instrucción crea un archivo de configuración, para después contruir el kernel. Prodría decirse que, se trata de una _plantilla_, con la que trabajar sobre un kernel de _uso general_. Una forma rápida de genererar el _arichivo de configuración_.

La lista completa de opciones al respecto, viene en el _log_ de ayuda, pudiendo ser consultado con `make help`, desde la línea de comandos.


---

#### < a name="#i5">Opciones de depuración</a>

En ambos casos, es una mala idea tomar por defecto las siguientes prácticas. AVISO. 
- Mantener una copia del `.config` con el que se compiló el núcleo. 
- Activar la característica `General Setup -> kernel .config support`. 
		$ cat /proc/config.gz | gunzip > /tmp/running.config
		or ...
		$ 2cat /proc/config.gz > /tmp/running.config

Ésta práctica únicamente es recomendable cuando se depura el núcleo. Es la excepción, ya que  es cuando resulta útil. Pero no hay que olvidar desactivar la característica y borrar cualquier rastro de tal archivo. ¿Por qué? pues por que si algo/alguien accede al equipo con privilegios suficientes, podrá replicar el núcleo del sistema. 

> __nota:__ siempre y cuando el sujeto tenga la capacidad, los drivers y dispositivos 
> o en su defecto, una máquina capaz de emular dichos componentes!


La siguiente entrada de blog, es una práctica sobre como compilar las herramientas de depuración del _kernel_. Dejo algunos de los enlaces como _lectura recomendada_.


__Construir el depurador__

A continuación se detallarán características necesarias, para llevar a cabo tareas de depuración sobre el kernel...

Lo mejor es poner un enlace a las páginas de documentación, que detallan el tema:

[Documentation/admin-guide/README.rst](URL)
[Documentation/acpi/aml-debugger.txt](URL)
[Documentation/acpi/debug.txt](URL)
[Documentation/process/changes.rst](URL)


TODO -- hay que traducirlas.


<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>
