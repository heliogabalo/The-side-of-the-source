[4 consejos par mejorar la experiencia con tmux](#i1)
[Configurar la terminal con tmux](#i2)
[Usar el zum, para centrar un proceso](#i3)
[Vinculación de algunos comandos útiles](#i4)
[Uso de _powerline_, una terminal moderna](#i5)
[Referencias y agradecimientos](#i99)


### [4 consejos par mejorar la experiencia con tmux](i1) ###

La utilidad `tmux`; un terminal multiplezador, permite tratar el terminal como una ventana _multi panel_ del sistema. Agrupar la configuración, lanzar distintos procesos en cada uno y, generalmente _hacer mejor uso_ del monitor. Lectores más acostumbrados, podrán repasar el árticulo [inicial]($miTmux1), de esta poderosa herramienta. Aquí hay algunos _consejos_, que ayudarán a sacar mayor partido de _tmux_, si _dolor epsum sit amet_.

El artículo asume las teclas <kbd>Ctrl + b</kbd>, vinculadas por defecto. Si fueron cambiadas los _atajos de teclado_, sustituirlo en su lugar.


### [Configurar la terminal con tmux](i2) ###

Uno de los grandes beneficios de tmux, es su capacidad para conectar y desconectar una sesión, _a lo salvaje_. Esto convierte el inicio de sesión remoto, en una herramienta poderosa. ¿Alguna vez has perdido la conexión y, deseado regresar al trabajo, en el sistema remoto? Con tmux este problema está resuelto.

En ocasiones, nos encontraremos trabajando en el servidor remoto, advirtiendo después, que no hemos iniciado sesión. Una forma de evitar esto, es definir `tmux start` o `tmux attach` en cada inicio de sesión o `login`, vinculado al sistema con la shell interactiva.

Añadir lo siguiente, al archivo <u>`~/.bash_profile`</u> del sistema remoto:

		if [ -z "$TMUX" ]; then
				tmux attach -t default || tmux new -s default
		fi

Cerrar sesión en el sistema remoto y, reconectar con SSH. Esto conducirá a una sesión tmux llamada _default_. La sesión será regenerada en el siguiente inicio de sesión en caso de salir. Más importante, de haber desacoplado de manera habitual, el trabajo aún seguirá esperándonos la próxima vez que _iniciemos_ -especialmente útil si la conexión fue interrumpida.

Por supuesto, es posible añadir la función al sistema local. Las terminales dentro de la mayoría de GUIs, no usan la sesión por defecto de manera automática, por que no son _escudos de inicio_. Aunque es posible cambiar este comportamiento, podría conducir a _sesiones anidadas_, poco útiles; conviene proceder con caución.


### [Usar el zum, para centrar un proceso](i3) ###

Aunque el objetivo de tmux, sea ofrecer múltiples ventanas, paneles y procesos en una sóla sesión, en ocasiones habrá que _centrar un proceso_. Supervisar un proceso, podría requerir más espacio -tal vez se trate de una tarea. El comando zum resultará de gran utilidad. Expande el panel activo, ocupando todo el espacio de la ventana.

El zum puede resultar útil otras situaciones. Por ejemplo, imaginemos utilizar una ventana de terminal, en un escritorio gráfico. Los paneles, podrían hacer dificil el copiar y pegar múltiples líneas dentro de la sesión tmux. Aumentar el panel, simplificará la tarea de copiar y pegar límpiamente múltiples líneas.

Para aumentar el panel activo, <kbd>Ctrl + b</kbd> más <kbd>z</kbd>. Repetir la combinación de teclas al terminar.


### [Vinculación de algunos comandos útiles](i4) ###

Por defecto, tmux dispone de númerosos comandos disponibles. Resulta de gran ayuda, reunir los más utilizados, vinculándolos a _teclas rápidas_. Aquí hay algunos ejemplos, que podremos añadir al archivo de configuración `~/.tmux.conf`.

		bind r source-file ~/.tmux.conf \; display "Reloaded config"

El comando anterior relee el archivo de configuración. Una vez añadida la vinculación, salir de cualquier sesión tmux y reconectar. Antes de hacer ningún otro cambio, sostener <kbd>Ctrl + b</kbd> más <kbd>r</kbd> y, los cambios serán parte de la sesión existente.

		bind V split-window -h
		bind H split-window

Estos comandos, facilitan la división de la ventana en un panel vertical y horizontal, respectivamente. 

> __nota d. t.__: las letras están en mayúscula! <kbd>Ctrl + b</kbd> más <kbd>Shift+V</kbd>... <br> esto podría deberse a que tmux ya vinculó las minúsculas. No bastará cambiar _la raíz_ adoptando el estilo _screen_ <kbd>Ctrl + a</kbd>. Esto sobreescribiría igualmente la combinación por defecto![cita Requerida].

Si fuese necesario ver todas las teclas vinculadas: <kbd>Ctrl + b</kbd> más <kbd>?</kbd>. Primero aparecerán las teclas vinculadas en _modo copia_, con las que trabajar dentro tmux. El modo _prefijo de vinculación_ mostrará los cambios añadidos arriba. Es recomendable experimentar, _siempre y cuando, no metamos los dedos en el enchufe_.


### [Uso de _powerline_, una terminal moderna](i5) ###

Publicado en anteriores artículos Fedora Magazine, la aplicación [powerline]($miEscudoGuai), es una _fantástica_ extensión a la _shell_. Aumenta las capacidades de tmux. Puesto que tmux ocupa la terminal al completo, la ventana _powerline_ proporciona mas, que sólo una terminal bonita. Escribir `git status` y, acción.

![Captura de pantalla powerline](images/tmux4.png)

Si powerline no fue instalado siguiendo las instrucciones del [artículo]($powderIsAlive), proceder a con _sudo_:

		sudo dnf install tmux-powerline

Es el momento de reiniciar sesión, podrá distinguirse su barra de estado en el borde inferior.
Dependiendo del _ancho de terminal_, la barra mostrará el ID de sesión, ventanas abiertas, información de sistema, fecha y hora y el nombre de la máquina. Al cambiar de directorio dentro de una _repo git_, aparecerá la _rama_ y su estado en el color preciso.

El grado de configuración es el adecuado, por lo que la imaginación, juega una papel principal. Disfrutar de la tecnología, en un presente experimental, _mola_.


### [Referencias y agradecimientos](i99) ###

[Fedora Magazine](fedoramagazine.org)

<ul id="firma">
	<li><b>Autor:</b> Paul W. Frields</li>
</ul>

<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>
