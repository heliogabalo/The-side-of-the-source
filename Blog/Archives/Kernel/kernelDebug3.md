#### Campo de pruebas WARNING WARNING WARNING ####

También existe la posibilidad de crear una imagen ISO:

		$ make -j8 isoimage
		

> __-j__ esta opci'on le dice al compilador el numero de trabajos simultaneos
(o hilos/comprobar) durante la compilacion.
> hay que indagar sobre los hilos que soporta cada n'ucleo.


- [x]parches, gestión, etc  
	- aplicar o revertir cambios.	 
- [x]DVCS? como vamos a descargar la fuente  
- configuración, construcción e instalación  
	- instalación en el dom0  
	- Reconfiguración en caliente; con el sistema en funcionamiento.  
	- reconfiguración por medio de archivos `conf`  
	- Configuración con ncurses	 
	- hay otras, desde la consola debe poder hacerse  
- creacion imagen(paquete).  


### git-bisect ###



Utiliza una busqueda binaria para encontrar el commit que introdujo el _bug_.
		man git-bisect




### Procedimiento ###

		git bisect start
		git checkout <version>
		make clean && make proper
		zcat /proc/config.gz > .config
		make localmodconfig
		make -j16

Si la construcci'on tuvo exito:
 
		make modules_install
		cp -v arch/x86_64/boot/bzImage /boot/vmlinuz-<version>-x86_64
		cp /etc/mkinitcpio.d/linux411.preset /etc/mkinitcpio.d/linux<version>.preset
		vim /etc/mkinitcpio.d/linux<version>
		mkinitcpio -p linux<version>
		update-grub

Si fallo:

		git bisect skip


Sugerencia:

paso 1 -Arrancar el sistema con el ultimo kernel
paso 2 -Cuando vuelva a aparecer el error de acceso directo a memoria ...

`[Jun 3 09:32] ata1: lost interrupt (Status 0x50)
[  +0.000014] ata1.00: exception Emask 0x0 SAct 0x0 SErr 0x0 action 0x6 frozen
[  +0.000005] ata1.00: failed command: READ DMA
[  +0.000005] ata1.00: cmd c8/00:88:f0:19:6f/00:00:00:00:00/e1 tag 0 dma 69632 in
                       res 40/00:02:00:08:00/00:00:00:00:00/b0 Emask 0x4 (timeout)`

Cargar la version del kernel sin errores
paso 3 -Revisar el _log_ con `journalctl -b -1`, recuerda:

`-b` opci'on de arranque boot.
`-1` registro del ultimo arranque. Lee el man de `jouranlctl` para mas info.


---

#### < a name="#i6">Referencias</a>

[https://docs.fedoraproject.org/f26/install-guide]:[Fedora Installation Guide]
[https://en.wikibooks.org/wiki/How_To_Backup_Operating_Systems]:[How_To_Backup_Operating_Systems]
[https://www.kernel.org/doc]:[kernel-docs]
#### Reconstruir el kernel
[https://boot.fedoraproject.org/downloads]:[Reconstruir?]
#### DOWNLOAD
[https://dl.fedoraproject.org/pub/alt/bfo/bfo.iso]:[Downloads]
#### net isntall
[http://ipxe.org]:[Net-install]


seguimiento:
[git-bisct-Bugforum](https://www.linuxquestions.org/questions/linux-kernel-70/failed-command-read-dma-on-healthy-wd-disk-on-linux-4-12-a-4175618041/)

https://forum.manjaro.org/t/complete-freeze-on-boot-with-kernels-4-12/34557

https://forum.manjaro.org/t/complete-freeze-on-boot-with-kernels-4-12/34557/11
