## Tareas programadas

1. Anacron y Cron
	1.1 Anacron
	1.2 Cron
2. Control de acceso a cron
	2.1 Lista Blanca y negra
7. Referencias

---
#### Anacron y Cron

Básicamente, la diferencia entre _Anacron_ y _Cron_, es que el primero, no
diferencia entre si el sistema está encendido o no. Al contrario, _Cron_, asume
que el sistema está encendido siempre, por lo que si el sistema está apagado,
sencillamente, la tarea no se llevará a cabo.

_Anacron_, lleva un registro de todas las acciones que ha llevado a término,
por lo que si una tarea no se completa, debido a que el sistema se encontraba 
fuera de servicio, pondrá en marcha la tarea, cuando el sistema vuelva a estar
en funcionamiento.

Otra diferencia, es que _Anacron_, sólo puede llevar a cabo una tarea _una vez al
día_.

#### 1.1 Anacron

Anacron es útil, cuando nuestro sistema no siempre está en funcionamiento, por que
todas aquellas tareas que se omitieron, debido a la ausencia de servicio del sistema,
serán controladas desde aquí.

Por el contrario, si se sabe que el sistema siempre está en marcha, podría decidirse
su _no utilización_, en tal caso, hay que desisntalar el paquete...

pathDir:  
		/etc/anacrontab  

#### 1.2 Cron



pathDir:  
		/etc/crontab

---
<.> the point is the original command for <source>
 */1 * * * *	. $GLOBVARS
 Pull all global variables, this is the first job that occurs once. So the stab is not polluted with the same entrie over & over.
 El enfoque de la aplicacion(rsync), es coger una lista de variables -son todos los archivos y directorios que van a ser sincronizados, extrayendo todas las reglas ejem: includes/excludes/ etc. a archivos externos. Con esto conseguimos simplificar la llamada a la aplicacion, manteniendo reglas complejas, en archivos separados. 
 El enfoque que yo he preparado, es el opuesto; son construidas reglas in "situ" especificas para cada directorio o archivo. Hay mucho que refactorizar aqui, juas.
 IDEA -- coger la lista de variables, y preparar un "FILTER", en el archivo donde se incluye los directorios/archivos a sincronizar, tambien pueden incluirse las "reglas", aunque estas habra que colocarlas al principio del archivo, o de lo contrario no seran alcanzadas cuando deban aplicarse.
 Otra nota, "rsync" proporciona un mecanismo para evitar el borrado de archivos que fueron anteriormente "guardados(backed-up)", esto significa, que la regla "--delete" sobre directorios y archivos guardados con anterioridad, no sera aplicada!!. CONVIENE LEER LA PAGINA DE MANUAL.
 Otra nota, los filtros NO son rutas hacia la "X", es un PATRON de texto -algo asi como un REGEX, que tendra encuenta la aplicacion, sobre el directorio que se le dijo trabajase.



## 2. Referencias
[anacmron][somewhereDeepOnAHole]
