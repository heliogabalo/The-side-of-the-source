## Añadir espacio


#### Índice
1. Introducción
2. El gestor LVM  
	2.1 Nuevo Volumen Físico  
	2.2 Pvresize
3. Otras alternativas

4. Referencias
---

#### 1. Introdución

Distintas situaciones, han creado la necesidad de espacio en nuestro sistema. Así que  
trataremos de documentar la práctica, siguiendo el esquema que ya está en uso.  
De cualquier forma, aparecen muchas alternativas, para resolver la misma  
problemática, la mayoría de ellas no serán tratadas aquí.  

Desde _Territorio Linux_, tomamos un enfoque más conservardor, es decir, tratando de  
alterar la estructura del sistema de ficheros, lo mínimo posible.  

Estoy seguro de haber comentado en otro documento, la composición en cuanto al  
particionado de disco. Personalmente, encuentro el _LVM(Gestor Vol. lógicos)_,  
una herramienta imprescindible, así que desde un primer momento, se decidió  
delegar la estrategia del particionado, por cuestiones prácticas.  

Una de las cualidades del _LVM_, es que puede dejarse de pensar, en _discos duros_  
como dispositivo físico, conduciendonos a una idea algo más abstarcta; _dispositivos  
virtuales_, para cubrir una necesidad, cambiante, en constante evolución.  

Esta _idea_, libera al administrador de sistema, del rígido esquema, al que    
está acostumbrado. Es el fin de las particiones primarias y, el principio que otros  
sistemas operativos menos evolucionados, deberán integrar, si es que pretenden  
seguir el hilo, del desarrollo tecnológico.  

#### 2. El gestor LVM

Ante la disyuntiva de _generar_ más espacio disponible en el sistema, surgen _dos_  
alternativas inmediatas:  

- Crear un nuevo Volumen Físico_(PV)_.  
- Redimemsionar, alguno ya existente.  

La diferencia entre uno y otro -desde mi punto de vista, reside en una cuestión de  
seguridad administrativa, o de administración de sistema.  
Donde premia el desempeño del _espacio virtual_, en relación a los datos contenidos  
o, los permisos, necesarios para trabajar sobre distintos directorios.  

Por ejemplo; redimensionar la estructura del directorio raíz, nunca es una buena  
idea. Debido a que la lógica, nos habla de un directorio donde es completamente  
innecesario aumentar la disponibilidad de aplicaciones, para usos puntuales.  

Existen las herramientas suficientes, como `chroot`, que permitirán lanzar otros  
programas, con permisos más elevados. De esta forma, podrían enclaustrarse, procesos  
que requieren de permisos especiales.  

Por otro lado, redimensionar alguno de los espacios de usuario, podría resultar  
conveniente, si con ello, se consigue evitar aumentar en número, los _PV's_, ligados  
a dicho ámbito.  

Por ejemplo;  el administrador, en este caso concreto, se revelará menos  
dispuesto, a gestionar más dispositivos, para menos usuarios, es decir; tratará en  
la medida de lo posible, disgregar la información sobre dispositivos no contiguos.  
Dado que resulta mucho más sencillo, apuntar a una sóla dirección, que empezar a  
crear punteros o, apuntar, sobre distintas localidades.  

####	2.1 Nuevo Volumen Físico  



#### 3. Otras alternativas

Añadir un nuevo disco, contratar espacio en la nube o establecer un enlace de acceso  
a otra máquina con espacio disponible, dentro o fuera de la red local.  
Son un puñado de ejemplos, que dan una idea real, de _otras_ alternativas posibles  
a la hora de resolver la práctica tratada en esta _entrada_.  


---

#### Referencias

[https://www.linuxtechi.com/extend-volume-group-size][Extend LVM partition size when there is no free space in the Volume Group]

