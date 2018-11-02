[Potenciar la terminal con tmux](#i1)
[Inicio de la aplicación tmux](#i2)
[La barra de estado](#i3)
[Comandos básicos](#i4)
[Acoplar y desacoplar](#i5)
[Segunda lectura](#i6)
[Referencias y agradecimientos](#i99)


# Potenciar la terminal con tmux #

Algunos usuarios Fedora, emplean la mayor parte de su tiempo sobre una línea de comandos. La terminal da acceso a todo el sistema, así como a miles de utilidades de gran potencial. En cualquier caso, sólo muestra una línea de comando por sesión. Incluso en grandes ventanas <kbd>alt + ctrl + F*</kbd>, únicamente mostrará una sesión. Resulta un desperdicio de espacio, especialmente sobre grandes monitores y, pantallas portátiles de grandes dimensiones. Pero ¿Qué sucedería si fuera posible dividir la pantalla en múltiples sesiones? aquí es donde `tmux` resulta útil -algunos dicen, indispensable!


### [Inicio de la aplicación tmux](i2) ###

El nombre de la utilidad tmux, proviene de _terminal muxer_, o _multiplexer_ -en castellano _plexo_, significa _red formada por nervios ..._. En otras palabras, tiene la capacidad de dividir una sessión de terminal, en múltiples sesiones. Puede gestionar tanto ventanas como paneles:

- Ventana, _vista_ única -una mezcla de cosas vistas en el terminal.
- Panel, es una parte de la _vista, habitualmente una sesión de terminal.

Para empezar, habrá que instalar dicha utilidad en el sistema. Es necesario configurar `sudo`, con la cuenta de usuario (compruesba las instrucción en [éste](URL) artículo).

		sudo dnf -y install tmux

Lanzar la aplicación para empezar:
		
		$ tmux


### [La barra de estado](i3) ###

Al principio, da la sensación de no aparece nada, excepto la barra de estado que aparece en el borde inferior del terminal:

![Barra de estado](/images/Tmux/tmux1.png)

La barra de estado muestra:

- `[0]` Nos encontramos en la primera sesión, qu fue creada por el servidor tmux. La numeración empieza en `0`. El servidor siguirá todas las sesiones que estuviesen o no, activas.
- `0:username@host:~` Información acerca de la primera ventana de la sesión. La numeración empieza en `0`. La terminal en el panel activo de la ventana, es propiedad del usuario `username` nombre de dominio `host`. El _directorio activo_[f1](#f1), en este caso `~/` ó `/home`.
- `*` Muestra la _ventana activa_.
- `hostname` El nombre anfitrión, del servidor tmux utilizado.
- También, la fecha y hora de la sesión en particular.

La barra de información, cambiará al añadir otras ventanas y paneles, a la sesión.


### [Comandos básicos](i4) ###

_Arrastrar la ventana_ del terminal, para hacerla más grande. Ahora experimentaremos con unos pocos comandos, con el fin de crear nuevos paneles. Por defecto, todos los comandos empiezan con <kbd>Ctrl + b</kbd>.

Sostener <kbd>Ctrl + b</kbd> más <kbd>"</kbd>, para dibidir en horizontal el panel. Ahora tendremos dos _paneles de línea_ en la ventana; uno arriba, otro abajo. Observar que el nuevo panel inferior, es el panel activo.

Sostener <kbd>Ctrl + b</kbd> más <kbd>%</kbd>, para dividir en vertical, el panel activo. Ahora tendremos tres _paneles de línea_ en la ventana; El nuevo panel inferior derecho, es el panel activo.

![Barra de estado](/images/Tmux/tmux2.png)

El borde resaltado delimita el panel activo. Para navegar entre paneles:

Sostener <kbd>Ctrl + b</kbd> más _flecha direccional_,
Sostener <kbd>Ctrl + b</kbd> más _q_, aparecerán los números de panel. Durante este breve momento, será posible pulsar el número asociado al panel.

Intentar utilizar los paneles para practicar los anteriores comandos. 

Por ejemplo,
- Escribir `ls`, para mostrar en el panel superior, el contenido del directorio.
- Lanzar _vi_, en el panel inferior izquierdo, para editar un archivo de texto.
- Lanzar _top_, en el panel inferior derecho, para monitorizar procesos en el sistema.

La siguiente imagen, muestra algo similar:

![Barra de estado](/images/Tmux/tmux3.png)

Hasta ahora, ha sido utilizada una ventana con múltiples paneles. Es posible _abrir_ múltiples ventanas en la misma sesión.

- Crear nuevas ventanas; sostener <kbd>Ctrl + b</kbd> más <kbd>c</kbd>. La barra de estado, mostrará dos ventanas. En la anterior imagen podrá observarse el detalle.
- Para _saltar_ a la ventana anterior, sostener <kbd>Ctrl + b</kbd> más <kbd>p</kbd>.
- _Saltar_ a la ventana siguiente; sostener <kbd>Ctrl + b</kbd> más <kbd>n</kbd>.
- <kbd>Ctrl + b</kbd> más número `0-9`, sitúa una ventana en particular.

Si estás pensando cómo cerrar el panel, usa el comando habitual sobre dicho panel `exit`, `logout`,[f2](#f2) o <kbd>Ctrl + d</kbd>. Una vez cerrados todos los paneles de la ventana, esa ventana desaparecerá de igual modo.


### [Acoplar y desacoplar](i5) ###

Una de las características más _..._	 de tmux, es la habilidad desacoplar y _re-acoplar_ una sesión. 
Es posible dejar las aplicaciones lanzadas, al desacoplar. Es más, incluso salir del sistema, `logout` -_cerrar sesión_, por completo. Más tarde, podremos `login`[f3](#f3) -iniciar sesión, _al mismo sistema_ y, _re-acoplar_ la sesión de tmux. Esto permitirá que veamos todas la ventanas y paneles donde lo dejamos. Los comandos lanzados, seguirán en funcionamiento aunque hayamos _desacoplado_.

Para desacoplar una sesión <kbd>Ctrl + b</kbd> más <kbd>d</kbd>. La sesión desaparecerá, retornándonos a la _shell_ anterior. Utilizar el siguiente comando, para _re-acoplar_ sesión:

		tmux attach-session
		
Ésta función, es también un _salvavidas_, cuando el conexionado de red es algo _caprichoso_. Si la conexión falla, todos los procesos de la sesión seguirán en funcionamiento. Una vez haya sido restablecida la conexión, habrá que retomar el trabajo, como si nada hubiese sucedido.

De no ser suficiente, es posible lanzar múltiples sesiones, sobre múltiples ventanas y paneles. Listar las sesiones y, acoplar después la correcta, por número o por nombre;

		tmux list-sessions


### [Segunda lectura](i6) ###

Este artículo sólo araña la superficie encuanto a las capacidades de tmux. Existen otras muchas formas de _manipular_ la sesión:

- Intercambiar un panel con otro.
- Mover un panel a otra ventana(en la misma sesión, o en otra distinta).
- Configurar _atajos de teclado_ y, llamar a los comandos de forma automática. 
- Inicia un archivo `touch ~/.tmux.conf`, con la confiruación _destacada_ por defecto; en cada nueva sesión, en la forma, color y tamaño deseado!

Seguir el enlace a continuación, con información más detallada -inicio de la serie de artículos dedicados a tmux.

[Server Hub]($myServerHub)


### [Referencias y agradecimientos](i99) ###



- [f1](f1) __directorio activo__: no confundir con _Active directory_. Nos referimos al directorio sobre el que trabaja la terminal.
- [f2](f2) __logout__
- [f3](f3) __login__

---
[Archivo de configuración]($miTmux.conf) 
[Fedora magazine](fedoramagazine.org)

<ul id="firma">
	<li><b>Autor:</b> Paul W. Frields</li>
</ul>

<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>

