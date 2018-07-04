## Reasignación de espacio dentro de la _LVM_


El escenario es el siguiente:

			--- Physical volume ---
			PV Name               /dev/sda(Primaria)
			VG Name               miVG
			PV Size               25,00 GiB / not usable 3,00 MiB
			Allocatable           yes (but full)
			PE Size               4,00 MiB
			Total PE              6400
			Free PE               0
			Allocated PE          6400
			PV UUID               YooHuu-YooHuu-YooHuu-YooHuu-YooHuu-YooHuu-YooHuu
			 
			--- Physical volume ---
			PV Name               /dev/sda(Extendida->logica)
			VG Name               miVG-elOtro
			PV Size               25,01 GiB / not usable 4,00 MiB
			Allocatable           yes 
			PE Size               4,00 MiB
			Total PE              6402
			Free PE               2
			Allocated PE          6400
			PV UUID               YooHuu-YHuu-YooHuu-YHuu-YooHuu-YHuu-YooHuu
			 

En un principio, se instaló un sistema operativo que por motivos que no vienen
ahora al caso, dejó de ser _usable_. El caso es, que tenemos un _PV_ del que se
puede prescindir, tanto de su contenido -la información que contiene, como del
espacio físico que ocupa en disco.

__nota:__ _el comando_ `lvmdiskscan` _lista todos los dispositivos de bloque_
_que hayamos construido en nuestro/s disco duro, marcando en la última_ 
_columna el PV._

#### Conservador

Si se quisiera conservar la información, exite una opción para mezclar(to merge)
ambos _PV's_, reasignar el espacio disponible a otro _LV_ o, guardar el espacio
libre, dentro de la piscina(pool) que compremnde el _VG_.

		...
		
#### Reciclado

Por otro lado, como el administrador del sistema, fue lo suficiente previsor,
y se hicieron copias de seguridad(backUps) suficientes como para no preocuparse,
lo justo, es que ahora que está tan de moda todo eso del reciclado, se haga lo
propio.

En este punto, surge un problema; como la particón conteniendo el _PV_ que 
queremos borrar, antecede a la que ocupa el sistema en _uso_, y ademas son
de tipos distintos(primaria/lógica) podría darse el caso, que empezasemos a
experimentar _errores de disco_.

Para evitar futuros errores de este tipo, en lugar de borrar complétamente el
_PV_ en `/dev/sda(primaria)`, lo que se hará, será extinguir los _LV's_ y, el 
_VG_, si se quiere. Pero siempre en éste orden. __Primero__ borramos los _LV's_.


__nota:__ _lo de borrar el VG, es opcional, por que en este caso concreto,_
_coincide en tamaño con el del PV_. _Así que la solución simple será renombrarlo._

			--- Volume group ---
			VG Name               miVG
			System ID
			Format                lvm2
			Metadata Areas        1
			Metadata Sequence No  23
			VG Access             read/write
			VG Status             resizable
			MAX LV                0
			Cur LV                4
			Open LV               0
			Max PV                0
			Cur PV                1
			Act PV                1
			VG Size               25,00 GiB
			PE Size               4,00 MiB
			Total PE              6400
			Alloc PE / Size       6400 / 25,00 GiB
			Free  PE / Size       0 / 0
			VG UUID               YooHuu-YooHuu-YooHuu-YooHuu-YooHuu-YooHuu-YooHuu


La hoja de ruta queda de la siguiente manera:

	1. Borrar o no, el contenido de los _LV's(a bit cero?)_
	2. Borrar el dispositivo. `lvremove /dev/VGname/NombrePartición`.
	3. Renombrar el VG. `vgrename miVG miNuevoVGname`.


#### 1. Decidir que hacer con los datos que contiene el LV en cuestion.
En linux es habitual el uso de herramientas que nos ayuden a decidir que
hacer con nuestra información.

- `rm -R` a lo bruto, borra absolutamente todo.
- `shred` y su útil página de manual, para los más cautos.
- __Cron__ es un gestor de tareas programable. Entre ellas, llevar a cabo
copias de seguridad del sistema, cuando toque.
- `rsync` y su página de manual, para aquellos que prefieran subir a la nube
copias de seguridad, aquí aparece otra vez __Cron__.
- `scp` y su página de manual, para llevar a cavo copias de archivos, mediante
una _shell segura(ssh)_.

		...
		
Hay muchas otras opciones!

#### 2. Borrar el dispositivo

Antes de borrar el dispositivo, habrá que cerciorarse de que no está montado.
Por eso, este tipo de gestión, _mola_ hacerla desde el _SO_, en "caliente", pero
_mola_ más, hacerlas con las herramientas adecuadas, por ejemplo __GParted__.

De esta forma, el administrador puede estar seguro de que no hay ningún _FS_, 
montado. 

En este caso se va a optar por la solución sensible, es decir, el administrador
no dispone de un disco de arranque y, tampoco se le ocurrio crear un particionado
de disco, con las herramientas necesarias para cargar un sistema mínimo de
mantenimiento[nota aquí].

Así que habrá que rodar hacia atrás -como dicen los ingleses(rollback).
Mortal o no, el salto hacía atrás, es necesario que sea llevado a cabo a lo
_Frank Sinatra(On My Way...)_

- Desmontar el dispositivo _LS_

		umount /dev/VGname/NombrePartición

Hay que aclarar que en este caso, tal partición no está montada, por que estoy
borrando _LV's_ fuera del sistema donde trabajo, son parte de un _SO_ en desuso.
Por tanto es innecesario desmontar la partición. 

En éste mismo paso, debería comprobarse, que como digo, tal partición no 
aparece en el `/etc/fstab` del sistema en uso, ya que de aparecer, podría
entrar en conflicto el gestor de arranque, cuando iniciemos el sistema.

Esto es, si tratamos de borrar la `root`, y resulta que aún lo tenemos 
metido en `fstab`. Resumiendo, habrá que borrar la entrada de tal 
dispositivo en `/etc/fstab`.


- Borrar el Volumen Lógico(_LV_).
Antes de borrar nada, debería tenerse en cuenta si la variable boleana
`metadata/record_lvs_history` en el archivo de configuración `/etc/lvm/lvm.conf`
está activada o no. Esto quiere decir que el gestor de la _LVM_ guarda un 
registro de los cambios que se producen en el sistema de ficheros. 

Cuando la variable está desactivada, resulta una información muy resumida. Podemos
verla con `lvs -H`. Pero en caso de tenerla activada, si pedimos el histórico 
de cambios al sistema, debería aparecer el nombre del dispositivo "borrado", junto
a un resumen histórico, sobre los cambios que se han llevado a cabo.

__nota:__ tal y como dice la página de manual `man lvremove`, debería aparecer
el nombre del dispositivo precedido por un guión `-/dev/VGname/NombrePartición`, 
así que para borrar el histórico, habría que volver a ejecutar el comando,
precediendo el nombre del dispositivo con el guón `-`. Eso, eso, borremos la 
historia.

- Renombrar el Grupo de Volúmenes.

		vgrename myVGname myNuevoVGname
		
Bastante simple. En lugar de ir borrando innecesariamente la particción y
tener que volver a crearla o, andar trasteando con los merge los pool, etc,
Ha sido preparada una nueva partición que será utilizada como _MV's_, pero
eso será otro día.
