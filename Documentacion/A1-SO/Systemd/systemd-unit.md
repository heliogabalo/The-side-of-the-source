## Systemd.unit

Un archivo de configuración de _Unidad_, codifica información sobre un servicio, un zócalo,  
un dispositivo, un punto de montaje, un punto de montaje automático, una partición o archivo  
de intercambio, un objetivo de arranque, una ruta vigilada para un sistema de ficheros, un  
_reloj(timer)_ controlado y, supervisado por _systemd(1)_, una porción de un recurso de  
gestión o, grupo de un poroceso externamente creado.

La sintaxis está inspirada por una especificación[1]de archivo `.desktop` dada en `XDG Desktop`  
que en resumidas cuentas, está inspirado por los archivos `.ini` _Microsoft Windows_.

Ésta página de manual, las oconfiguraciones de opciones comunes, de todos los tipos de unidades.  
Estas opciones, deben ser configuradas en las secciones `[Unit]` ó `[Install]` de los archivos  
de configuración.

Además de las secciones genéricas `[Unit]` y `[Install]` aquí descritas, cada unidad, podría  
tener una sección de _tipo_ específico, ejem.: `[Service]` para un servicio de unidad. ver las  
respectivas páginas de manual(man pages), para más información: `systemd.service(5)`, 
`systemd.socket(5)`, `systemd.device((5)`, `systemd.mount(5)`, `systemd.automount(5)`,  
`systemd.swap(5)`, `systemd.target(5)`, `systemd.path(5)`, `systemd.timer(5)`, `systemd.slice(5)`,  
`systemd.scope(5)`.

Son permitidas varias configuraciones, especificadas más de una vez, en cuyo caso, su interpretación  
dependerá de la configuración. A menudo, múltiples configuraciones forman un lista y, configurar  
un valor vacío reinicia la variable`(void)`, lo que significa que una previa asignación será 
ignorada.

Cuando esto está permitido, es mencionado en la descripción de la configuración. Nótese que el  
uso de múltiples asignaciones al mismo valor, provoca que un archivo sea incompatible con los  
analizadores de sentencia(parsers) de _XDG_.




> __socket:__ traducido como zócalo, podría traducirse como puerto, pero debido a que el término
> _puerto_ es utilizado para referirse a un conenctor físico y también a una arquitectura de
> máquina(ejem. `086`, `x86_64`, `ARM`, etc), es preferible evitar su traducción de esa forma.

__slice:__ portion or share, pedacito, porción.
