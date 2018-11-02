[Añade poentcia a la cónsola con powerline](#i1)
[Con tmux, el multiplezador](#i2)
[Powerline con vim](#i3)
[Configuración de Powerline](#i4)
[Referencias y agradecimientos](#i99)

# [Añade poentcia a la cónsola con powerline](i1) #

Hace unos meses, Fedora Magacine publicó una entrevista con _Rackspace_ , donde se mencionó la utilidad _powerline_. Para aquellos que trabajen de forma continuada sobre la cónsola,  
podrían encontrar en powerline, una herramienta de gran utilidad. Powerline, entraga una barra de información, concisa y, clara, a la que nada falta. Tampoco sobra.

Entre sus componentes, podrán encontrarse:

- <kbd>Login name</kbd>
- <kbd>Local Time</kbd>
- Directorio activo o <kbd>ruta</kbd>. La ruta es _simplificada_, al crecer por encima del ancho de terminal.
- El número de <kbd>trabajos</kbd> activos en segundo plano.
- El <kbd>hostname</kbd>, al conectar mediante SSH a un servidor remoto. Siempre sobre la máquina instalada.

Ahorra un tiempo significativo en la configuración del entorno de línea y, evita complejos _escritos_. Para su instalación, proceder de la siguiente manera:

		sudo dnf install powerline powerline-fonts

La instalación asume una términal _bash_ básica, en cualquier instalación Fedora. En cualquier otro caso, es conveniente revisar la documentación correspondiente.

A continuación, habrá que configurar el terminal _bash_, para que utilice porwerline por defecto. Añadiríamos entonces, el siguiente _recorte_ al archivo de configuración `~/.bashrc`:

		if [ -f `which powerline-daemon` ]; then
			powerline-daemon -q
			POWERLINE_BASH_CONTINUATION=1
			POWERLINE_BASH_SELECT=1
			. /usr/share/powerline/bash/powerline.sh
		fi

Para que los cambios tomen efecto, abrir de nuevo otro terminal y, comprobar que todo fue bien. Sirva la foto, como ejemplo de muestra.

![Terminal Bash con Powerline](images/Tmux/tpower1.png)

Intentar cambiar de directorio. Observar como cambia el _prompt_, para mostra la ruta actual. Es un poco ... _a gusto del consumidor_. En Territorio Linux, encontramos que para tabajar sobre _la bash_ -cariñosamente hablando, no necesitamos nada más, que un cursor modesto, y sin demasiado brillo. Ya se sabe lo que dice la gente acerca de los focos de Brodway! En cambio sobre el multiplexador, glorioso.es.


### [Con tmux, el multiplezador](i2) ###

Algunos gurús de cónsola, también conocerán _tmux_ -esta serie de artículos dedicada! Permite dividir la terminal, [etc, etc]($miTmux1). 
A la barra de estado de tmux le falta un poco de _ge nu se cuá_. Probablemente por que es una aplicación algo menos moderna. Desde nuestro punto de vista, es aquí donde powerline, ilumina una oscura noche, para acomodar los datos sin deslumbar, con medida y todo lujo es _un detalle_. 

Características incluidas en la interfaz:

- Información de ventana.
- Sistema cargado.
- Hora y fecha.
- Nombre de máquina, durante una conexión de _shell_ degura o SSH.

Proseguir con la configuración, exige instalar primero, el _plugin_ powerline:

		sudo dnf install tmux-powerline
		
El siguiente paso será añadir una pequeña línea al archivo de configuración,

`~/.tmux.conf`
		source "/usr/share/tmux/powerline.conf"

Editar el archivo de configuración, otra vez, comentando las líneas referidas a `status-left, status-right, status-left-length` y `status-right-length`. Todos los ajustes son siempre opcionales, destinados a concretar _nuestras preferencias_.

El archivo de usuario `tmux.conf`, bajo la ruta `home/`, dispone de _modelos_ de muestra, en caso de no existir. Pueden ser encontrados en la ruta de _compartidos_ `/usr/share/tmux` y después copiados a `~/.tmux.conf`. En cualquier caso, hay docenas de modelos, que otros usuario han _subido_ en la red. La siguiente imagen dibuja el ejemplo.

![Sesión tmux con powerline](images/Tmux/tpower2.png)


### [Powerline con vim](#i3) ###

El editor Vim, integra la _vista_ powerline a duras penas, mejor que en Bash; puesto que el editor es _menos exigente_ en cuestiones de espacio. La barra estado debería estar integrada en el _marco_ de la aplicación. En la foto puede apreciarse que esto no se cumple, consumiendo un espacio extra. Sin embargo, valoramos positivamente esta "modificación" del editor, puesto que Vim, es mucho más que un editor, es un _entorno de programación_. 

Cualidades:

- Modo operación -norma, insertar, reemplazar.
- Ruta activa y nombre de archivo
- Codificación del texto.
- Documento y posición de línea

La instalación seguría el proceder habitual:

		sudo dnf install vim-powerline

Tan sólo queda editar el archvo de configuración, en este caso `~/.vimrc` y, solapar unas pocas líneas para conseguir que _arranque_ con la _modificación_:

		python3 from powerline.vim import setup as powerline_setup
		python3 powerline_setup()
		python3 del powerline_setup
		set laststatus=2 " Always display the statusline in all windows
		set showtabline=2 " Always display the tabline, even if there is only one tab
		set noshowmode " Hide the default mode text (e.g. -- INSERT -- below the statusline)
		set t_Co=256

Lanazar la aplicación nuevamente, para que los cambios surtan efecto.

![Vim con Powerline](images/Tmux/tpower3.png)


### [Configuración de Powerline](i4) ###

Es cierto que la mayoría de aplicaciones de línea, deban ser configuradas de _uno u otro modo_. En Territorio Linux hemos batallado alguna que otra vez, con archivos de este tipo _JSON_. Nosotros los utilizamos como _arreglos_; archivos de datos -o fuentes de datos, que pueden ser consultadas por otras aplicaciones _web_. Pero aquí, podemos ver que el _tipo_ de archivo está siendo utilizando para dar formato, al estilo de la aplicación Powerline. Olé. Por que es un archivo facilón, nada complicado y en cierto grado, intuitivo. 

> por supuesto, la ignorancia del que subscribe, degrada la utilidad que pudiera o pudiese tener el tal JSON.

- Variables de entorno
- Datos, para el sistema de control de versión(git entre ellos).
- _Tiempo atmosférico, o condiciones climatológicas_.
- Otras alternativas.

Para cambiar el _perfil_ de la barra de entorno, será creados o editados, los archivos de configuración en la carpeta`~/.config/powerline/`. Las configuraciones son guardadas como _tema_, respectivo al _plugin_. La aplicación Power-lint, comprueba mediante el analizador de sentencias, los archivos de configuración tras realizar algún cambio.

Determinados cambios, podrían requerir volver a _cargar sesión_, o incluso reinicias el _demonio_:

		powerline-daemon --replace

El trabajo está hecho. Es momento de brillar, disfrutar y, de agradecer al _usuario_ su esfuerzo por haber llegado hasta el fondo -deeel teeexto!


### [Referencias y agradecimientos](i99) ###

- [Fedora Magazine](fedoramagazine.org)
- [Rackspace](https://www.rackspace.com/)
- [Powerline](https://powerline.readthedocs.io/en/latest/)
- [JSON.org/](http://json.org/)
- [How to JSON](https://powerline.readthedocs.io/en/latest/configuration.html)



<ul id="firma">
	<li><b>Autor:</b> Paul W. Frields</li>
</ul>

<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>
