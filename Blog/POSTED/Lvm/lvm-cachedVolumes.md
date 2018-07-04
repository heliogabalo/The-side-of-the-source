## Caché LVM

#### Descripción

La idea aquí es crear un volúmen lógico donde almacenar muchos datos. Sería
un ejemplo perfecto una gran base de datos.

En lugar de almacenar todos los datos mezclados, se compartimentalizarán, 
en otros _LV's_, consiguiendo con esto mayor eficiencia en la lectura/escritura
hacia el dispositivo.

Esto se consigue almacenando los _bloques de uso frecuente_, en _LV's_ mas
rápidos -ya que estarán contruidos para almacenar datos específicos.
El gestor _LV_, se refiere a estos pequeños y rápidos _LV's_, como :
__cache pool LV__

> caché de volumen lógico.

Debido a los requisitos del própio gestor, esta "caché" de _LV_, se dividirá
a su vez en dos dispositivos:

	- __cache data LV:__ es donde las copias de bloques de datos son guardados
	_(desde OriginLV)_, para aumentar la velocidad.
	- __cache metadata:__ éste sostiene la información que especifica dónde están
	almacenados los bloques de datos -podría ser en _OriginLV_ o _cache data LV_.

#### Términos

- origin LV 			---  large slow LV
- cache data LV 	---  small fast LV for cache pool data
- cache metadata	---  small fast LV for cache pool metadata
- cache pool LV		---	 CacheDataLV + CacheMetaLV
- cache LV				---  OriginLV + CachePoolLV

---
Método principal de uso:

0. Crear `OriginLV`
	
		nomenclatura: lvcreate -n OriginLV -L LargeSize VG SlowPVs
		# lvcreate -n OriginLV -L 15G VGcached

	Este paso propone crear un volumen, como lo haríamos normalmente:
	- se especifica el nombre, el tamaño y el nombre del grupo de
	volumenes al que queramos asociar o el nombre de grupo que tendrá
	en caso de no existir el _VG_(esto último es una suposición).

>> Había un contruidos un _PV_ y su respectivo _VG_, por lo que_
>> _El Origin parte con un tamaño de 15G, PV=25G, y quedará un remanente_
>> _en el PV de aproximadamente otros 5G._

1. Crear `CacheDataLV`

		nomenclatura: lvcreate -n CacheDataLV -L CacheSize VG FastPVs
		# lvcreate -n cacheDatos -L 2G VGcached /dev/myPVdevice

	El tamaño de este _LV_ será considerado como el tamaño de __cache pool LV__.

>> Siguiendo un esquema proporcional donde Origin tiene 100G, éste _LV_
>> lo haríamos de 10G, por lo que en nuestro ejemplo sería de 1.5G. Para
>> trabajar con números redondos, lo vamos a hacer de 2G.

2. Crear `CacheMetaLV`

		nomenclatura: lvcreate -n CacheMetaLV -L MetaSize VG FastPVs
		# lvcreate -n CacheMetaLV -L 8M VGcached /dev/myPVdevice
		

	Aquí el tamaño del dispositivo es una referencia marginal. Debería ser
	unas 1000 (mil) veces más pequeño que el _LV cache datos_, 8M min.

>> Una curiosidad, es que se apunta un __PV__ cuando me refiero al dispositivo
>> donde está alojado el grupo de volúmenes, mmm... esto suena a _disco de estado
>> sólido(o SSD)!!_. 


3. Crear `CachePoolLV`

		nomenclatura: lvconver --type cache-pool --poolmetadata VG/CacheMetaLV
		# lconvert --type cache-pool --poolmetadata VG/CacheMetaLV VG/cacheData
		
		
	Los _LV's_ _cacheDatos_ y _cacheMetaLV_, se combinan para formar el 
	_cache pool LV_. El comportamiento de este _cache pool LV_, podrá ser
	determinado en este paso.
	- __CachePoolLV__ toma en nombre de _CacheDataLV_.
	- __CacheDataLV__ es renombrado como CachePoolLV_cdata y será ocultado.
	- __CacheMetaLV__ es renombrado como CachePoolLV_cmeta y será ocultado.
		
>> En este punto, el sistema me devuelve un Aviso

		WARNING: Converting logical volume VG/cacheDatos and VG/cacheMetaLV to  
		pool's data and metadata volumes.  
		THIS WILL DESTROY CONTENT OF LOGICAL VOLUME (filesystem etc.)  
		Do you really want to convert VG/cacheDatos and VG/cacheMetaLV? [y/n]: y  
		Converted VG/cacheDatos to cache pool.

>> Pero además, el gestos ha interpretado `--poolmetadata` 
>> por `--poolmetadataspare`, creando un _LV_ adicional, destinado a la 
>> recuperación automática de la piscina de meta datos. Esto claramente 
>> es un _bug_ del gestor. 
>> Podría borrarlo, pero como no se que va a suceder si lo hago, y si 
>> se lo que es, aprovecho para probar la funcionalidad!


4. Crear CacheLV

		lvconvert --type cache --cachepool vg/cacheData vg/OriginLV
		# lvconvert --type cache --cachepool VG/cacheDatos VG/OriginLV

		# lvs -a VG   
		LV                 VG    Attr       LSize  Pool         Origin Data%  Meta%  Move Log Cpy%Sync Convert
		OriginLV           VG    Cwi-a-C--- 15,00g [cacheDatos]        0,00   3,47            100,00
		[OriginLV_corig]   VG    owi-aoC--- 15,00g
		[cacheDatos]       VG    Cwi---C---  2,00g										 0,00   3,47            100,00
		[cacheDatos_cdata] VG    Cwi-ao----  2,00g
		[cacheDatos_cmeta] VG    ewi-ao----  8,00m
		[lvol0_pmspare]    VG    ewi-------  8,00m
