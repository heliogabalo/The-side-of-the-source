1. [ScummVM](#1i)
  1. [Qué no es ScummVM](#1i1)
2. [Inicio rápido](#2i)
3. [La interface gráfica de scummVM](#3i)
4. [Conseguir juegos](#4i)
5. [Obteniendo ayuda](#5i)
6. [Apendice](#6i)
---

## 1. <a name="1i">ScummVM</a>
ScummVM es un programa que te permitirá volver a utilizar tus viejos juegos, sobre un entorno más 
moderno...
Se centra principalmente en juegos de tipo RPG(rol) y point-and-click(de ratón). 
La clave de _ScummVM_, es que únicamente reemplaza el archivo ejecutable del juego, por lo que
te permitirá jugar en otras plataformas(sistema operativo), sobre la que fué originalmente diseñado.

> Scumm: Script Creation Utility for Maniac Mansion - utilidad de script para Maniac Mansion.
> VM: Virtual Machine.

#### <a name='1i1'>Qué no és ScummVM</a>

ScummVM no es una forma de conseguir gratuitamente cualquier juego. Se que suena mal, pero hay
que recordar, que muchos desarrolladores aún no han liberado el código fuente de sus aplicaciones 
-aunque eso, es otro tema que no viene a colación.

Basta decir, que aunque el _código_ no esté liberado, si es posible conseguir ese juego que quieres;
por decirlo de forma simple, en ocasiones las distribuidoras, desarroladores y demás, llegan a 
acuerdos comerciales con otras compañías, con el objeto de promover nuevas relaciones, etc.
Recuerdo que unas pocas navidades atrás, encontré en Steam, el Elder Scroll: Skyrim, por 0,98€. 
Como lo digo; no llegaba a un euro. Supongo que podréis imaginar lo que tardé en comrarlo!. Ese, y 
el _Metal gear_por 1,80€.

El caso es, que sucede algo parecido con este tipo de software _antiguo_. Van rotando, en ocasiones
lo encontraréis gratis, y justo cuando se empieza a correr la voz, la cosa cambia y el juego deja de
estar gratuitamente disponible.

Lo bueno, es que siempre hay alguno gratís. Aquí la clave es darse una vuelta por tu página de 
confianza, y mirar a ver que hay!

Otra forma de utilizar el virtualizador, es mirar en el cajón de juegos viejos, a ver si hay 
escondido algo por ahí. ¿Quien no tiene un juego viejo, arrinconado y polvoriento? Lo sé, lo sé, 
pero desgraciadamente, esos chavales necesitan otras cosas antes [http://whakamua.org][whaka], así 
que no te sientas culpable por hacer _brillar_ de nuevo esos CD's y _flopys_...

...Como sabréis, los _streams_ o _torrente de datos_ son archivos que contienen información en 
lenguaje binario, que fácilmente puede ser interpretada desde qualquier systema operativo.
Es por esto que scummVM, únicamente necesita cambiar el ejecutable. 
Habitualmente estos archivos, guardan la información de imágenes, sónido etc. por lo que si ya
te gastaste el dinero una vez, no es necesario que vuelvas a hacerlo. Eso sí, el CD, debe estar
en buenas condiciones, claro!

## <a name='2i'>Inicio rápido</a>
Lo primero es descargar e instalar _ScummV_. Seleccionar el que se ajuste a tu sistema operativo o
distribución, y click sobre el enlace para comenzar la descarga.
En _Territorio Linux_, hemos preparado el archivo apropiado del _cliente_, para evitar tener que
buscarlo en la lista, pero si aún así prefieres echarle un ojo, aquí dejo la lista completa:

  - [ScummVM][scum]

#### Resumen:

  1. Descargar ScummVM.
  2. Conseguir el juego.
  3. Comprobar que ScummVM tiene acceso a la
     carpeta del juego.
  4. Lanzar ScummVM.
  5. Seleccionar el juego a través de la interface
     de ScummVM.
  6. Lanzar el juego desde la interface ScummVM.

__En Windows__, hay que asegurarse de tener el [WinZip][winzip] o [7-zip][7zip], personalmente 
prefiro éste último, que además cuenta con funciones de compresión/descompresión, desde el clíck 
secundario del ratón. Una vez descargado el archivo, abre la carpeta de descaga. Descomprimir 
pulsando botón secundario sobre el archivo, e instalar dando doble click sobre el archivo 
descomprimido. 

Con esto, queda instalado el virtualizador de aplicación, _ScummVM_.
[Windows-instaler][Windows-installer] <-- este es `.exe`. Instalación automática.
[Windows-zip][Windows-zip] <-- formato comprimido.

Ahora, si tienes el juego original debería hacerse una copia o imagen del disco/s y grabarse en el
disco duro. Esto pude hacerse lanzando el instalador del própio juego o, copiando el contenido de 
los discos originales, en alguna carpeta de usurario.
Únicamente será necesario comprobar que _ScummVM_ tenga acceso a la carpeta donde quedó guardado el
juego.

 
> Como se decía al principio del artículo, _ScummVM_ solo necesita un grupo de archivos en concreto.
> ¿Qué archivos? ah, esta es la cuestión, no es por fastidiar, pero ocurre que los desarrolladores 
> cuando créan el proyecto -el juego en este caso, nombran a la extensión del archivo de datos como
> mejor les parece(por razones bastante obvias). 
> 
> Así que hay que estudiar caso por caso(el juego), para descifrar como el desarrollador a compuesto 
> el proyecto. Generalmente se utilizan extensiones con denominación canónica, es decir, universal. 
> Pero no siempre es así!  

__En Linux:__

He visto que en ocasiones -no las he probado todas, el archivo viene empaquetado, esto es habitual
en _Linux_. Si es este el caso, basta con abrir el gestor gráfico de archivos, por ejemplo 
_Nautilus_ y doble click sobre el archvo. Esto debería comenzar el proceso de instalación 

[Ubuntu][Ubuntu]
[Fedora][Fedora]
[Macintosh][Macintosh]

En linux este tipo de operaciones es bastante fácil, por que el própio sistema operativo, sule 
llevar las herramientas necasarias, por defecto:

La sintaxis es bien sencilla: `dd if=[origen] of=[destino]`

  $ dd if=/dev/cdrom of=/home/user/imagenCD.iso
  $ mount -o loop imagedeCD.iso /mnt/home

La primera línea de comando copia el contenido del CD, en la carpeta de usuario, con el nombre
_imagenCD.iso_. Con el segundo, nos situamos sobre el directorio `cd ~/user` y montamos la imagen
_iso_, sobre el directorio previamente creado: `$ mkdir /mnt/home`.
Volvemos a guardar el CD en la caja y, miramos a ver que archivos son necesarios. 

  $ cd /mnt/home && df -h

Podemos evitar este paso, volviendo a copiar el contenido íntegro del disco, en la carpeta
que queramos, dentro de nuestro espacio de usuario, esto es `/home/user`.
Si por el contrario queremos evitar copiar todo el contenido, hay que echarle un ojo a la página
de _ScummVM_, donde se detallan los archivos _usado_ para el juego en cuestión.


> Los usuarios de Macintosh, encontrarán útil los _recomendados_ en Linux.

_Android_
Puede aplicarse el proceso descrito en cualquiera de las secciones anteriores _Windows/Linux_. 
Cuando el archivo del juego haya sido descargado, habrá que buscar en la carpeta de descargas,
o bien en la carpeta `clouddrive`, si el archivo ya ha sido descomprimido. Hemos encontrado que
podrían haber pequeñas diferencias de un dispositivo a otro, en cuánto a la ruta de descarga y
posterior descompresión.

Os agradecemos cualquier comentario al respecto.

[Android][Android]


_PS3_

[PS3][PS3]

El proseceso de instalación tanto del cliente _ScummVM_ como de los _juegos_, es muy parecido al de
otras plataformas, aunque antes habrá que tener instalado una versión específica del sistema 
operativo. De cualquier otra forma, no funcionará.

Como el proceso es algo complejo, preferimos dedicar un artículo completo sobre este tema.
Tan solo diré que debe quedar instalado un _firmware_ no privativo. Realizando una búsqueda en
_Google_ con algo parecido a esto: `homebrew PS3 custom firmware` se deberían encontrar páginas
de tutorial, sobre como llevar a cabo esta tarea. 



> Si tu plataforma no está en ninguna de las listas anteriores, únicamente debes mirar en la página
> [ScummVM-stables][scum], donde seguro encuentras el instalador de _ScumVM_ apropiado.


## <a name="3i">La interface gráfica de scummVM</a>

## <a name="3i">Conseguir juegos</a>

En la página de _ScummVM_ [data-files][data], hay una lista muy larga, pero en la que no están
los enlaces a las descargas. Estoy convencido que se habrá entendido qué és esta lista.
Pero por si alguno se ha despistado; nada mas que contiene un resumen de aquellos archivos que 
seran _necesarios_, para que _ScummVM_ pueda carga el videojuego.
Por lo tanto, o bien descargamos el contenido que _Sí_ está disponible, o bien lo conseguimos por 
otros medios[poner enlace a gog punto com aquí]. 

En el momento de redactar esta página, hay disponibles 7(siete), vieojuegos clasificados como 
_freeware_, -usease: gratis!.
Estos son:

  1. [Beneath a Steel Sky][bass]
  2. [Drascula: The Vampire Strikes Back][drascula]
  3. [Dreamweb][dreamweb]
  4. [Flight of the Amazon Queen][fotaq]
  5. [Lure of the Temptress][lure]
  6. [Sfnix][sfnix]
  7. [Soltys][soltys]

Otros recursos que recomendamos tener instalados son:

  - [SDL][sdl]  <-- Librería SDL. Simple DirectMedia Layer.
  - [Opcional][opt]  <-- Al final de la página, encontraréis la lista bajo "Optional Libraries".

El resto, son archivos de sonido, componentes extra para un juego determinado, texturas, etc. 
Otra cosa importante que debe quedar clara, es que con estas descargas, no hablamos de sistema
operativo. La misma descarga sirve para la _play_, _tablet_ o _pc_(windows/linux/mac).

El equipo de Territorio Linux, tratará de mantener una lista dinámica de aplicaciones, siempre y 
cuando, el desarrolador o distribuidor de la aplicación, proporcione el contenido libre. Esto quiere
decir, que no siempre estarán los mismos juegos, y que en todo momento, nuestra compañia se reserva
el derecho de añadir o quitar contenido, sugún la particularidad de la situación.

> Con esta _pequeña_ regla, buscamos _armonizar_, lo que el desarrollador 
> entiende por _derechos de autor_, y lo que en realidad significa DRI.


##<a name="3i">Obteniendo ayuda</a>

## <a name='6i'>Apendice</a>

#### Aplicaciones de sistema y útiles -- Resumen

[WinZip][winzip]
[7-zip][7zip]
- Daemon tools
- 

---
[whaka]: http://whakamua.org
[scum]: http://www.scummvm.org/downloads/#stable
[winzip]: www.winzip.com
[7zip]: http://www.7-zip.org/
[data]: http://wiki.scummvm.org/index.php/Datafiles
[Windows-zip]: http://territoriolinux.net/00Z771b/Windows/scummvm-1.9.0.2-win32.zip
[Windows-installer]: http://territoriolinux.net/00Z771b/Windows/scummvm-1.9.0.2-win32.exe
[Ubuntu]: http://territoriolinux.net/00Z771b/Ubuntu/scummvm_1.9.0-xenial.1_amd64.deb
[Fedora]: http://territoriolinux.net/00Z771b/Fedora/scummvm-1.9.0-1.x86_64.rpm
[Macintosh]: http://territoriolinux.net/00Z771b/Macintosh/scummvm-1.9.0-macosx-ppc.dmg
[PS3]: http://territoriolinux.net/00Z771b/PS3/scummvm-1.9.0-ps3.zip
[Android]: http://territoriolinux.net/00Z771b/Android/scummvm-1.9.0-android-all.apk 
[opt]: http://www.scummvm.org/downloads/
[sdl]: https://www.libsdl.org/index.php
[bass]: http://territoriolinux.net/00Z771a/Bass/bass-cd-1.2.zip
[drascula]: http://territoriolinux.net/00Z771a/Drascula/drascula-int-1.0.zip
[dreamweb]: http://territoriolinux.net/00Z771a/Dreamweb/dreamweb-cd-es-1.1.zip
[fotaq]: http://territoriolinux.net/00Z771a/FOTAQ/FOTAQ_Talkie-1.1.zip
[lure]: http://territoriolinux.net/00Z771a/Lure/lure-es-1.1.zip
[sfinx]: http://territoriolinux.net/00Z771a/Sfinx/sfinx-en-v1.1.zip
[soltys]: http://territoriolinux.net/00Z771a/Soltys/soltys-es-v1.0.zip







