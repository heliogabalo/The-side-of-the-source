1. cpusets
	 1.1 Qué son los `cpusets`
	 1.2 Por qué son necesarios los `cpusets`
	 1.3 Cómo son implementados los `cpusets`
	 1.4 Que son `cpusets` _exclusivos_
	 1.5 Qué es `memory_pressure`
	 1.6 Qué es `memory spread`
	 1.7 Qué es `sched_load_balance`
	 1.8 Qué es `sched_relax_domain_level`
	 1.9 Cómo usar el `cpusets`
2. Ejemplos de uso y sintaxis
	 2.1 Uso básico
	 2.2 Añadir/quitar _CPU_'s
	 2.3 Establecer opciones
	 2.4 _Acoplar_ procesos
3. Preguntas
4. Contacto
99. Referencias y agradecimeintos
---

## cpusets

#### Qué son los `cpusets`

Proporciona un mecanismo para la asignación de conjuntos de CPUs y nodos de memoria,  
a un _grupo de tareas_. En éste documento _Nodo de memoria_ se refiere a un nodo  
_en línea_ que contiene memoria.

_Cpusets_ restringe los recursos de la CPU y el direccionado de memoria de tareas, 
a las tareas en uso por el `cpuset`. Forma una estructura gerarquica, visible en el
_sistema de archivo_ virtual. Son en esencia los _enlaces -o ganchos(hooks)_: al  
margen de _lo que esté presente_ en el sistema, para gestionar el emplazamiento de  
trabajos en grandes sistemas.

_Cpusets_ usa un subsistema `cgroup` genérico descrito en 
`Documentation/cgroup-v1/cgroups.txt`.

Las peticiones de una tarea, haciendo uso de la llamada de sistema `sched_setaffinity(2)`  
para incluir CPU's en su _máscara de afinidad_, y usando `mbind(2)` y `set_mempolicy(2)`  
para incluir _nodos de memoria_ en la _política de memoria_, serán filtrados a través  
de las tareas de `cpuset`, el cuál excluirá cualquier CPU o _nodo de memoria_ que no  
esté en ese `cpuset`.

La agenda, no indexará una tarea en la CPU que no esté permitida en el vector  
`cpus_allowed`, y el _emplazador_ de páginas del _kernel_, no colocará ninguna  
página en un nodo no permitido, en la petición del tarea para el vector `mems_allowed`.

> __scheduler:__ agenda, diario, programa, hoja de ruta

El código en el espacio de usuario, puede crear y destruir `cpusets` por nombre; en el  
sistema de archivos virtual `cgroup`. Gestionar los atributos y permisos de los `cpusets`  
y qué _CPUs y nodos de memoria_ son asignados a cada `cpuset`. Especificar y consultar  
en qué `cpuset` fué asignada una tarea y, listar el `pid` de tarea asignado a un 
determinado  `cpuset`.

> __pid:__ process identifier, identificador de proceso.


#### Por qué son necesarios los `cpusets`

La gestión de grandes sistemas de computación, con muchos procesadores (CPUs), 
y complejas jerarquiías para la caché y múltiples nodos de memoria con acceso no
uniforme (NUMA), presenta desafios adicionales, en cuanto al "indexado" y el  
emplazamiento de memoria para los procesos.

> __NUMA:__ non uniform memory acces, acceso a memoria no uniforme.
> __agenda:__ se usa el término agenda, en el sentido de _programa_ u "hoja de ruta",
> de tal forma que una tarea pueda llevarse a cabo de manera programática o planificada.  

Sobre sistemas con _tamaños modestos_, puede operarse con una adecuada eficiencia,  
con tan sólo dejar que el sistema operativo, comparta automáticamente las CPUs y los  
recursos de memoria para la _peticiones de tareas_.

Pero en sistemas mayores, los cuáles se benefician más, de un _cuidadoso_ emplazamiento
de la memoria y del procesador, para reducir el número de _accesos a memoria_ y contención,
el cuál típicamente representa una gran inversión para el cliente, puede beneficiarse 
si explícitamente son emplazados determinados trabajos, sobre _subconjuntos de sistemas_  
apropiadamente dimensionados.

Ésto podría ser especialmente valioso en:

- Servidores Web, corriendo múltiples instancias de la misma aplicación web
- Servidores corriendo distintas aplicaciones (ejem. un servidor web y una base de datos).
- Sistemas NUMA, corriendo grandes aplicaciones HPC, con mucha demanda.

> __HPC:__ High Performance Computing, servidores con grandes cargas de trabajo.

Éstos subconjuntos -o _particiones blandas_, deben ser capaces de ser dinámicamente  
ajustadas, cuando el trabajo cambie, sin afectar a otros trabajos concurrentes, en  
ejecución. La localización de las _páginas de trabajos_ en carrera, podrían ser movidas  
cuando los emplazamientos de memoria, sean cambiados.

Los parches `cpuset` del _kernel_, proporcionan un mecanismo esencial, a la hora de  
implementar dichos subconjuntos. Presionando existentes CPUs y el emplazamiento de  
memoria de dichas infraestructuras en el _núcleo_, con objeto de evitar cualquier  
impacto sobre el gestor programático o, código de emplazamiento de memoria.  

> __concurrente:__ que sucede en un mismo momento, o lugar. "La turba enfurecida concurrió
en la plaza del pueblo". "El pregón se dirigía a ellos: queridos concurrentes..."


#### Cómo son implementados los `cpusets`

_Cpusets_ proporciona al _kernel de Linux_, un mecanismo que obliga a dichas CPUs y,  
nodos de memoria, a ser usados por un proceso o conjunto de procesos.

De hecho, en _kernel de Linux_



## Referencias y agradecimeintos

Copyright (C) 2004 BULL SA.
Written by Simon.Derr@bull.net

Portions Copyright (c) 2004-2006 Silicon Graphics, Inc.
Modified by Paul Jackson <pj@sgi.com>
Modified by Christoph Lameter <cl@linux.com>
Modified by Paul Menage <menage@google.com>
Modified by Hidetoshi Seto <seto.hidetoshi@jp.fujitsu.com>

> __kernel de Linux:__ se refiere al núcleo de un sistema operativo, que ha tomado el  
> nombre, de la persona -y su grupo de investigadores, que _desarrolló y liberó_, el código
> del núcleo del sistema operativo.

> __GNU:__ es un acrónimo recursivo para _"GNU no es UNIX"_, por que está basado en 
> código _UNIX_, pero difiere de éste, en que es _código libre_ y no contiene _código UNIX_.
> Es un sistema operativo y, un _conjunto_ de aplicaciones, programas, configuraciones,
> que son incorporadas por las _distribuciones_, de muchos de los sistemas operativos  
> basados en el _kernel de Linux_. __Richard Stallman__, fué su fundador.

> __Linux Torvald:__ para mí, es un referente que explica la diferencia entre lo que significa  
> ambición y, avaricia. Para otros, la _wikipedia_ resultará una fuente de conocimiento 
> inestimable.





















