#### Backups rápidos.

Me parece oportuno explicar aquí, el proceso que yo he seguido, para que
nadie lo tome en consideración -o quizás sí!!, y sirva de ejemplo auto-correctivo.

		--- Logical volume ---
		LV Path                /dev/multimedia/home-extra
		LV Name                home-extra
		VG Name                multimedia

Lo único que hice fue crear un _LV_, donde contener las capturas.
El problema es que al tomar la decisión de crear la captura, con la
siguiente comprovación:

		# df -h /
		S.ficheros              Tamaño Usados  Disp Uso% Montado en
		/dev/mapper/mi-root		    15G   4,5G  9,5G  32% 	/

_Pensé; vale, si el disco es de `15G` y sólo he usado `4,5`, voy a crear una
"imagen" de `10G`, y de ésta forma ahorro un poco de disco!!. Craso error, por
que la primera regla a la hora de copiar una imagen de disco es:_
> La imagen destino debe ser, mayor o igual a la imagen origen, _NUNCA_  
> inferior.

		# lvcreate -L 10G -s -n rootcaptura /dev/mi_VG/root
		Logical volume "rootcaptura" created.

Con lo que al realizar de nuevo la comprovación:

		# lvdisplay
		...
		# open                 0
		LV Size                15,00 GiB
		Current LE             3840
		COW-table size         10,00 GiB
		...
		Allocated to snapshot  0.00%
		...

Aparece un dato desconcertante, el gestor _LVM_ ha sido capaz de entender que
estaba tratando de copiar una imagen más grande de lo que le dije que sería, y
así lo refleja con el tamaño del _LV_. Pero el tamaño de la tabla `COW`
_copy-on-write_, es de sólo `10G`.  
Esto significa que una vez el disco contenga más información que el límite
marcado en la tabla `COW`, los datos excedidos, no sólo _NO_ se escribiran en la
captura, sino que dejarán inútil la imagen.

¿De qué sirve entonces proceder de esta forma? pués cuando conocemos de antemano
el espacio que va contener la partición donde se realiza la captura. Es una forma
rápida de crear un _"backup"_.

A continuación debe montarse el dispositivo:
		# mkdir /mnt/backup-of
		# mount /dev/mapper/rootcaptura /mnt/backup-of

Comprovación sobre el directorio montado:
		# ls -l /mnt/backup-of
> Debe aparecer el contenido de la partición que hemos montado.

El dato en el que hay que fijarse es el progreso de la información guardada en
la captura:

Al principio miramos el estado de _LV_ con `# lvdisplay`, volvemos hacerlo
buscando el siguiente dato:

		...
		Allocated to snapshot  0.00%
		...
> Antes de borrar el contenido del directorio '/mnt/backup-of'

		...
		Allocated to snapshot  12.30%
		...
> Después de borrar los datos.



Ahora, sin desmontar el _LV_, borramos el contenido del directorio.
		`# rm -f /mnt/backup-of/*.iso`
		# ls -l /mnt/backup-of
> Deben haberse borrado los datos.

Para recuperarlo:
		# umount /mnt/backup-of
		# lvconvert --merge /dev/mapper/rootcaptura
		# mount /dev/mapper/rootcaptura /mnt/backup-of
		# ls -l /mnt/backup-of

> Primero se desmonta el _LV_, a continuación se _fusionan_ los datos de la
captura, vuelve a montarse el dispositivo y comprobamos nuevamente.


__Conclusión:__, técnicamente hablando, esto no es una copia de respaldo o _backup_,
es _algo_ parecido. Resulta interesante el espacio alojado en la captura,
__después__ de borrar los datos. Parece el _mundo al revés_, y en cierta manera
es así; en la captura se está copiando la diferencia de información, con respecto
al momento en que tomamos la _instantánea_, es decir, no se ha clonado la información,
sino que se ha guardado un registro, con todos los:
_cambios/modificaciones/añadidos/sustraidos_ en el momento de tomar la captura.


> ver [Restaurar un backup][].


</div>
<button title="Click to show/hide content" type="button" onclick="if(document.getElementById('spoiler') .style.display=='none') {document.getElementById('spoiler') .style.display=''}else{document.getElementById('spoiler') .style.display='none'}">Oficial de derrota -- Click mostrar/ocultar</button>
