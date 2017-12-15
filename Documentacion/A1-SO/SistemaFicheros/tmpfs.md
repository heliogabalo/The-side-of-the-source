1. Tmpfs

99. Referencias y agradecimientos
999. Varios
---


## Tmpfs
`tmpfs` es un sistema de archivo guardando todos los _ficheros_ en memoria virtual.  

Cualquier cosa en `tmpfs` es _temporal_, en el sentido de que los _archivos_ no serán  
creados en el disco duro. Al desmontar un sistema de archivo cualquier _algo_ guardado en él,  
se perderá.

`tmpfs` guarda todo en las cachés internas del núcleo y, _crece o méngua_ para acomodar los
ficheros que contiene y, es capaz de intercambiar páginas innecesarias, fuera del espacio de  
intercambio. Tiene un límite máximo de tamaño, el cúal puede ser ajustado, al momento, por  
medio de `mount -o remount ...` 

Comparado con `ramfs` -el cuál fué la plantilla para crear `tmpfs`, se gana el intercambio y
límites de comprovación o coincidencia. El _disco RAM_ es algo similar(/dev/ram*), el cuál  
simula un espacio físico fijo en el disco duro, donde poder crear encima, sistemas de  
archivo _ordinarios_.
Los _discos RAM_ no pueden intercambiar, tampoco tienen la posibilidad de ser redimensionados.

Debido a que `tmpfs` está completamente integrado en la _página de caché_ y en la _memoria de_  
_intercambio_, todas las páginas `tmpfs` serán mostradas como "shmem"(memoria compartida) en  
`/proc/meminfo` y "Shared" en `free(1)`. Nótese que los _contadores_ incluyen la memoria  
compartida(`shmem`, ver `ipcs(1)`). Para obtener el contador lo mejor es usar `df(1)` y  
`du(1)`.

`tmpfgs` tiene los siguiente usos:

	1. Siempre hay un montaje interno del _kernel_, que no puede verse. Usado para  
	_mapas anónimos compartidos_ y, para _memoria compartida SYSV_.
	
	Éste _montaje_ no depende de `CONFIG_TMPFS`. Si `CONFIG_TMPFS` no es configurado, la  
	parte de _tmpfs_ visible por el usuario, no será construida. Pero el mecanismo interno  
	está siempre presente.
	
	2. _glibc 2.2_ y posterioresm, esperan que `tmpfs` sea montado sobre `/dev/shm`, 	
	para memoria compartida POSIX(shm_open, shm_unlink). Añadiendo la siguiente línea a  
	`/etc/fstab` debería tomar efecto:
	
		tmpfs	/dev/shm	tmpfs	defaults	0 0
		
	Recordar _crear_, el directorio donde montar `tmpfs` si fuese necesario.
	
	Tal montaje, _no es necesario_ para la memoria compartida de SYSV. El _montaje interno_ es  
	usado para eso. En versiones del kernel _v2.3_ fué necesario montar el predecesor de 
	_tmpfs(shm fs)_ para usar la memoria compartida de SYSV.	
	
	__POSIX:__ Portable Operating System Interfase UniX like, Interfase Portable para  
	Sistemas Operativos del tipo UniX.
	
	3. Algunas personas -incluido el autor del texto, encuentran muy conveniente montarlo,
	por ejemplo en `/tmp` y `/var/tmp` y tener una _gran_ partición de intercambio. Reiterar  
	el montaje de `tmpfs`(en plural), para que hagan su trabajo, y así, `mkinitrd` coincida
	con la mayoría de distribuciones, para que puedan montar `tmpfs` sobre `/tmp`.
	
	4. Probablemente muchas más...
	
tmpfs tiene tres opciones de montaje para el _tamaño_:

__size:__ el límite de _bytes direccionados_ por la instancia de _tmpfs_. Por defecto es
_half(medio)_ la mitad del espacio de RAM sin memoria de intercambio. Sobredimensionar  
la instancia de `tmpfs` la _máquina_ _morirá cerrada_ ya que el OOM -debe ser un mantra.
	


#### Referencias y agradecimientos

Author:
   Christoph Rohland <cr@sap.com>, 1.12.01
Updated:
   Hugh Dickins, 4 June 2007
Updated:
   KOSAKI Motohiro, 16 Mar 2010

#### Varios

> __fichero/archivo:__ En algunos idiomas, se hace una distinción entre estos dos términos,  
> aludiendo a un significado distinto; fichero sería la _unidad mínima divisible_ -por  
> así decirlo. Archivo, trata de referirse a un "contenedor" pudiendo guardar en su interior,  
> otras _unidades_. 
> En castellano ésta distición queda un poco fuera de lugar, ya que ambos terminos son usados 
> indistíntamente para referirse a lo mismo. Un fichero puede ser `unFichero.extension` ó 
> `/unDirectorio` ó `unPaquete.rpm`. Por lo que archivo como término, podría referirse  
> igualmente a cualquiera de ellos.
> fichero: lugar donde se guardan fichas. El orden es implícito por que sólo se guardan fichas.
> archivo: lugar donde se guardan cosas, de forma organizada. Por fichas, por fechas, por fajos.

__en el aire__: on the fly, en caliente, al momento. 
