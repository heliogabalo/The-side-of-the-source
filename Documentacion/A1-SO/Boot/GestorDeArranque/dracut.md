## Dracut

Es una infraestructura `initramfs`. 
Cuando _dracut_ es cargado, initramfs tiene un sólo propósito: cargar un 
_sistema de ficheros raíz_ y, poder hacer la transición, hacia un _FSroot_
real.rm

- udev



- `/dev/kmsg`
		


#### Redirección de la salida no interactiva

		exec >/dev/kmsg 2>&1 </dev/console


---
#### Definiciones

Estos comandos se utilizan sobre la línea de comando del nucleo.

- rdshell: carga la cónsola.
- rdshell rdinitdebug: imprime los comandos _dracut_.

---
#### Referencias

[dracut][https://dracut.wiki.kernel.org]
[fedoraproject][https://fedoraproject.org/wiki/How_to_debug_Dracut_problems]
