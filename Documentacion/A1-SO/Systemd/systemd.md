## indice

1. [Systemd](#i1)  
2. [Directorio de configuración y precedencia](#i2)  
3. [Relación entre .rc y targets(objetivos)](#i3)  
4. [Cambiar el objetivo(runlevel) con el sistema en marcha.](#i4)  

## Systemd

Systemd es el reemplazo de sysV, es un sistema más moderno, donde se han  
reemplazado las condiciones de carrera del sistema (race condition/run levels, _rc._),  
por un sistema basado en objetivos(_targets_).  

	$ systemctl get.default  
	
> identifica el _target_ o _run level_, en uso  

#### Directorio de configuración y precedencia 
Durante la compilación del núcleo se crean automáticamente unos archivos de configuración  
por defecto, aunque habrá que revisarlos por que están en su mayoría comentados.  

Para mantener una copia o plantilla, que después sirva como inicio de una nueva  
configuración, es conveniente hacer una copias de estas _guías_ a `/etc/systemd/user.conf.d`  
y realizar sobre este directorio los cambios que se ajusten a un determinado systema o  
configuración.  

Cuando una aplicación personaliza alguna de estas configuraciones, lo hace sobre el  
directorio `/usr/lib/systemd/*.conf.d/`. Los archivos de este tipo sobre `/etc/` son  
reservados para uso del administrador local, quien usará esta lógica para sobreescribir  
los archivos de configuración, instalados por el fabricante/distribuidor, etc.  

- El archivo de configuración principal es el primero en leerse, con menor precedencia.  
- Las entradas, en cualquier archivo de configuración, sobreescriben las entradas en otros  
	archivos de configuración.  
- Los archivos almacenados en subdirectorios de configuración `*.conf.d/` serán orndenados  
	por nombre de archivo, en lugar de por el directorio en que se encuentren.
- Si múltiples archivos, especifican la misma opción, se tomará en cuenta la última leída.


#### Relación entre .rc y targets(objetivos)

- Run level 0 -- poweroff.target  
	runlevel0 <--> enlace simbólico a poweroff.target  
- Run level 1 -- rescue.target  
	runlevel1 <--> simbólico a rescue.target  
- Run level 2 -- PERSONALIZADO USUARIO?? 
  runlevel2	<--> simbólico a  
- Run level 3 -- multi-user-target  
	runlevel3	<--> simbólico a multi-user-target  
- Run level 4 -- PERSONALIZADO USUARIO??  
	runlevel4 <--> simbólico a  
- Run level 5 -- graphical.target  
	runlevel5 <--> simbólico a graphical.target  
- Run level 6 -- reboot.target  
	runlevel6 <--> simbólico a reboot.target  
	
#### Cambiar el objetivo(runlevel) con el sistema en marcha.

	# systemctl isolate multi-user.target  
> ...con los permisos apropiados, se cambia el _run level_.  


#### Listado de dispositibvos

	systemctl list-units
	
> lista de unidades conocidad, según el man-page, revisar.


