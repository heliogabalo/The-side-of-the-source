[Run, run, run, la botella de run](#i1)
[Compilar Spigot](#i2)
[Iniciar el servidor](#i3)
[Configuración básica](#i4)
[Plugins](#i5)
[Referencias y agradecimientos](#i99)

# [Run, run, run, la botella de run](i1) #

Minecraft es uno de los vidojuegos más polulares, escritos hata la fecha. Cerca de 70 millones de _cuentas asociadas_, avalan la cifra. Después de jugar en modo _un jugador_, el siguiente paso acostumbra a ser el modo multi-jugador. Existen miles, de servidores en Mincraft. Los jugadores podrán unirse en ocasiones, en otras, cabe la posibilidad de crear nuestro propio servidor. El servidor más polular de Minecraft, es un _software_ llamado Spigot.

Spigot, es código de _fuente abierta_; un proyecto Java, que permite a los usuarios lanzar su própio servidor Minecraft. Además, es posible extender la funcionalidad del servidor, mediante _plugins_ -o progras pequeños que _modifican_ la aplicación principal. Lejos de extinguir sus existencias, los servidores Spigot se cuentan por cientos de miles, 100.000, aproximadamente. Adía de hoy, Spigot es uno de los servidore Minecraft, más estables, diversos y, sobre trodo disponibles!


### [Compilar Spigot](i2) ###

Hay que compilar la fuente. Para utilizar Spigot, es necesario utlizar varias _herramientas de  construcción_. La utilidad utliza la librería _Java_, así que primero habrá que instalarla:

		sudo dnf install java-1.8.0-openjdk git

Tras completar la instalación de la librería, el seguinete paso es descargar la última versión de las herramientas de construcción __BuildTools__, desde la página	[Spigot Jenkins](https://hub.spigotmc.org/jenkins/job/BuildTools/). Una vez descargada, crear un directorio para la misma y, situar allí el archivo. A conntinuación, abrir una teminal cambiando al directorio recién creado.
La compilación de __Spigot__, con los siguientes comandos,

		git config --global --unset core.autocrlf
		java -jar BuildTools.jar

El primer comando _git_, requiere haber instalado el DVCS primero. Consiste en una comprobación de los finales de lína del paquete BuildTools. Esto quiere decir que en Linux, utilizamos un código para el _final de carro_, distinto al que utilizan en Windows. El primer comando lleva a cabo esta comprobación y, convierte los archivos al formato adecuado.

El segundo comando, ejecuta un programa encapasulado en un archivo _JAR_. Para el que no lo sepa, cuando hablamos de _java_, hablamos de maquinas virtaules, de aplicaciones virtuales, o de alguna suerte de _proceso_ virtual. En definitiva, virtualización. 

> Escribo el comentario sólo por razones de _archivo_, es una cuestión interesante y, con toda seguridad, volveremos a tratar el tema en sucesivas entradas de blog.

Al terminar BuildTools, aparecerán nuevos archivos en el directorio, entre ellos, uno llamado `craftbukkit-1.x.x.jar` y, otro `spigot-1.x.x.jar`. La _x_ representa la versión de Minecraft. CraftBukkit es la implementación del servidor Minecraft, aunque dejó de ser mantenida de manera oficial, hace ya tiempo. El equipo _Spigot_, publica frecuentes actualizaciones de CraftBukkit. Spigot, es una rama alternativa -o fork, del proyecto CraftBukkit, con varias mejoras en rendimiento realizadas por la comunidad. 


### [Iniciar el servidor](i3) ###

Una vez listo el archivo `spigot-1.x.x.jar`, es el momento de iniciar el servidor. Hay una gran variedad de métodos para levarlo a cabo. Aquí utilizaremos un _software_ gestor de ventanas, llamado __tmux__, que permitirá lanzar el servidor, sin necesidad de mantener abierto un terminal.

La instalación de [tmux]($miTmux), describe detalladamente el proceso, aquí sólo pondremos el comando de _shell_ con el que descargar e instalar tmux, desde el repositorio de la distribución. Recomendamos seguir el artículo citado, pues la aplicación resulta _un poco caprichosa_, si nunca antes fue utilizada.

		sudo dnf install tmux

Seguiremos el hilo del artículo original, agradeciendo primero a _Justin W. Flory_, por su estupendo artículo ... y, escribiremos unas pocas líneas de configuración. Primero un pequeño _escrito bash_, a modo de _start-up_, -o escrito de inicio. Su contenido es el que sigue a continuación,

`start-spigot.sh`

		#!/bin/bash
		java -Xms1024M -Xmx1024M -jar spigot.jar

El archivo deberá situarse en el mismo directorio donde hemos estado tabajando hasta el momento. Los siguientes comandos de línea, crean una nueva sesión de tmux, e inician el servidor Mincraft,

		$ tmux new -s minecraft
		$ cd /path/to/spigot.jar
		$ chmod +x start.sh
		$ ./start.sh

Inicia el servidor Spigot, porporcionando más instrucciónes para su configuración.


### [Configuración básica](i4) ###

Hay unas pocas configuraciones básicas, consejos y, guías disponibles, con las que personalizar el servidor Spigot para hacerlo coincir con las preferencias de usuario. La  [wiki de Spigot](https://www.spigotmc.org/wiki/spigot-configuration-spigot-yml/)), cubre parte de estos ajustes, además de agrupar otro contenido interesante. Recomendamos echar un vistazo a la página.
Los dos archivos revisados `server.properties` y `spigot.yml`, son un punto de partida interesante, desde el que empezar a _trastear_ con el servidor.

__`server.properties`__

		server-ip
				Default: <empty>
Si el valor de la llave, está vacío `<empty>`, _localhost_ será el valor por defecto. Si la máquina no tiene múltiples direcciones IP, es aceptable dejarlo vacío.

		server-port
				Default: 25565
Especifica el puerto TCP, sobre el que escuchará el servidor Spigot.

		enable-query
				Default: false
Cambiar el valor a `true`, permite que servicios externos hagan `ping` al servidor, recavando información como la web asociada con el número de jugadores y _plugins_ activos.

		query.port
				<debe ser introducidad de forma manual>
Establecer el puerto UDP, con un número distinto al puerto TCP del servidor, evita que cualquiera desde internet, encuentre fácilmente, información acerca del servidor. Si no es necesario compartir: `Default: $miNumeroUDP`.

		max-players
				Default: 10

Determina el número de jugadores, que podrán jugar al mismo tiempo, en el servidor.

		motd
        Default: A Minecraft Server

Cambiar el nombre, para personalizar el servidor que aparecerá en el menú multi-jugador. Permite hasta dos líneas de texto; para indicar el MOTD, conviene utilizar la _caracter de escape_ `\n` -salto de línea.

__`spigot.yml`__

El archivo `spigot.yml` contiene la configuración por defecto, específica al servidor Spigot. Hay varias opciones que podrán cambarse. Si prima el rendimiento, alterar la configuración para maximizar el rendimiento, incluso en _sistemas viejos_. Una guía completa para la configuración, en la _wiki_ antes comentada. A continuación, serán detallados alguanas opciones.

		settings > restart-on-crash
En caso de _catastrofe ejecutiva_, reiniciará automáticamente mediante la llamada al _escrito de inicio_, creado anteriormente. Resulta especialmente útil, cuando el servidor deba estar en funcionamiento durante largos períodos. Comprobar que el archivo de `inicio.sh` aparece en esta línea.

		world-settings > anti-xray
Hay gran cantidad de _trucos_ en Minecraft. Uno de los más populares, es el de _rayos-x_. Éste, permite a los jugadores, ver a través de bloques parte del decorado, e inmediatamente encontrar, los bloques más valiosos tras ellos, _los recursos_.
El _motor de videojuego_ tiene dos modos; el __modo 1__ consiste en una ligera protección poco efectiva, aunque conserva los recursos. El __modo 2__ requiere más potencia de computación; _ofusca_ los bloques no visibles en el aire, para bloquear el truco de rayos-x. Habrá que averiguar cuál es el modo más conveniente.

		world-settings > dragon-death-sound-radius
Una de las características disponibles para el servidor Spigot. Es posible alterar el rango audible, del sonido _muerte del dragón_. Por defecto, todos los jugadores del servidor, podrán oirlo; modificar el radio de efecto sonoro, limíta quién lo oirá!

		world-settings > arrow-despawn-rate
Característica orientara al rendimiento. Si disminuye el _ratio de aparición_ de las flechas, es posible reducir la carga de renderización para tales objetos. Si los jugadores están continuamente disparándose _flechas y arcos_ -por los cielos! resulta un _truco_ conveniente, mejorando el rendimiento.


### [Plugins](i5) ###

Además de las opciones de configuración por defecto, Spigot viene con una API para desarrolladores Java, diseñada para escribir _plugins_ personalizados. El servidor Spigot acumula un considerable número de funcionalidad extra en formato _plugin_, nunca está de más echar un vistazo y, comprobar si alguno, se ajusta a algún tipo de interés que pudiese interesar a nuestros jugadores. 


### [Referencias y agradecimientos](i99) ###

-	[Spigot](https://www.spigotmc.org/wiki/spigot-configuration-spigot-yml/)
- [Fedora Magazine](fedoramagazine.org)
- [Archivo Java(JAR)](http://docs.oracle.com/javase/8/docs/technotes/guides/jar/index.html)
- java(1), página de manual.

__JIT__, Just in Time, ver [siglas](territoriolinux.net/TerritorioLinux/siglas.html).

<ul id="firma">
	<li><b>Autor:</b>Justin W. Flory</li>
</ul>

<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>
