## Uso de LVM

He observado que reducir el tamaño de un _Volumen Físico_, no es la mojor forma
de administrar el espacio del disco o discos asiginados al mismo. Creo haber
leído esto en algún manual, pero como es algo que no uso a diario, es fácil que
haya olvidado esto.

En ésta y otras entradas de _Blog_ intentaré ir apuntando todas estas cosas, así
que si alguien está leyendo esto como guía de uso, aconsejo mirar otras fuentes
antes de tomar a pies juntillas lo que se diga en las mismas[Advertencia]. 

Me ha resultado mucho más fácil redimensionar la partición que había creado 
para la instalación de un viejo SO, que tratar de reducir el tamaño del 
_Grupo de Volumenes_.

En un principio, mi intención fue añadir un nuevo _VG_ al _PV_ que había en la
partición, sin embargo para ello debía reducir el tamaño del _VG_ al que 
previamente había asignado todo el espacio libre del disco.

Al leer el comando que en teoría pretendía utilizar `vgreduce`, no vi demasiado 
claro como hacerlo, ya que el manual no hace referencias a tamaños ni particiones,
por lo que no parece una buena idea.

En lugar de eso me he limitado a reducir el tamaño de la partición y comprobar
que efectivamente, el nuevo tamaño del _VG_ se ajusta a la modificiación.

Después he dejado el espacio libre del disco sin asignar, y nuevamente una 
instalación en _limpio_ del nuevo _SO_. 

Así que para posteriores manipulaciónes del espacio, en el disco voy ha hacerlo 
así. La idea es que ahora no hay que reducir nada, el espacio en el _VG_ ha sido
creado en función de la necesidad. Si más adelante es necesario crear otro _VG_
simplemente basta con volver a crear uno nuevo e ir _montando_ los _LV's_ 
consecuentemente. Esto parece el procedimiento correcto!

Por otro lado, la idea inicial de asignar el espacio libre del disco al _VG_
en cuestión, no representa mayor problema, es más, podría incluso considerarse
una medida de seguridad, ya que estamos asignando un espacio "libre" que
como no está vinculado a ningún _LV_, tampoco puede ser usado. 

Es senciallamente una especie de _Limbo_ que es añadido al _VG_. Dicho de otra
forma, para poder reasignar éste espacio libre, habría que reducir la partición,
y entonces sí, añadir mas espacio a un determinado _VG_ o _LV_.

Todo esto viene a que en la documentación del _LVM_ hay una nota que apunta
a que no es posible la instalación de sistema operativo desde una partición
no marcada como de arranque, me estoy refiriendo al _boot_.

Esto no es así, comprobado. Sí es posible una instalación tipo _LVM_ sin
una partición específica para el _boot_. Es más, cuando es reinstalado el
gestor de arranque -obviamente por omisión, como subdirectorio dentro
de la _raíz_ de sistema, el nuevo gestor es capaz de leer las imagenes
de núcleo, instaladas con anterioridad. No sin embargo, otras imágenes
fuera de la que esté utilizando por defecto el _SO_.

Es decir, si se está utilizando el gestor de arranque para cargar una
imagen de otro tipo (por ejemplo un hipervisor), que hemos instalado
dentro del sistema, ya sea a través del gestor de paquetes de nuestra
distro, o bién tras haber compilado la fuente; no la carga, presumo
que al rescribir de nuevo el _MBR_, el gestor es capaza de leer las
imágenes que cuelgan del disco duro/s, sin embargo no ocurre lo mismo
con otras imágenes que hayamos instalado a traves del _sistema en uso_

Lo apunto, por que es curioso ver como la _imagen_ sigue ahí, y sin
embargo para que el gestor de arranque la lea, tendríamos que empezar
a mover archivos de forma un tanto _a lo bruto_.

En este caso, es mejor borrar la instalación "anidada" de la imagen
_arrancable_, y volver a hacerla __desde la instalacion del sistema
operativo que usa el gestor de arranque__ o bién hacer la instalación
de nuestro "extra" -en este caso el hipervisor, desde un _LiveCD_.
Donde previamente habremos comprobado que hay espacio suficiente el 
el disco. Esto último es un supuesto, ya que no lo he probado.
