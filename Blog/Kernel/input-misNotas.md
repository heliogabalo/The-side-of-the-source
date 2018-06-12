11. Significado de Mayor y Menor
22. Opciones par selecionar dispositivos

99. Referencias


## Input -mis notas



#### Opciones par selecionar dispositivos

 `lspci`
 
 -s [[[[<domain>]:]<bus>]:][<device>][.[<func>]]

Muestra sólo los dispositivos especificados en el dominio(en caso de que su máquina, disponga  
de distintos host bridges -NorthBridge o puente norte, podrían compartir un espacio común,  
para un número de buses, o cada uno de ellos, podría _direccionar_ un dominio PCI, por sí 
mismo; los dominios son numerados desde `0` a `ffff`), bus (`0`a `ff`), 
dispositivo de (`0` a `1f`) y funciones de (`0` a `7`).

Cada componente de la dirección del dispositivo, puede ser omitida ó marcada como `*`,  
en ambos casos significa lo mismo _"cualquier valor"_. Todos los números son _hexadecimales_  
Por ejemplo, 
	`0:`  --significa _todos los dispositivos en el bus 0_
	`0`   --significa _todas las funciones del dispositivo `0` en cualquier bus_
	`0.3` --significa _tercera función del dispositivo `0` en todos los buses_
	`.4`  --significa _mostrar sólo la cuarta función, de cada dispositivo_
	


#### Significado de Mayor y Menor

Con estas palabras, nos referimos -los programadores, al _bus de sistema_, el primer  
número indica el _dominio_ del que va a colgar nuestro dispositivo y, el segundo indica la  
_dispositivo_, el tercer número es la _función_ de un determinado dispositivo. Por ejemplo:  

		00:00.0 Host bridge: Intel Corporation 82G33/G31/P35/P31 Express DRAM Controller 
		
Las primeras cifras -leídas de izquierda a derecha, indica el _dominio_, se trata de un  
chip integrado en la placa base(el bus norte, NorthBrigh), en este caso se trata del  
bus más importante del sistema...

Siguiendo el ejemplo encontraríamos que tiene un _Mayor_ `00` y un _Menor_ `00` igualmente.
Esto es correcto, por que es el bus principal del sistema y el primero en ser leído.  

		00:02.0 VGA compatible controller: Intel Corporation 82G33/G31 Express Integrated  
		
Esto se pone interesante. Se ve el dispositivo, en este caso, la gráfica integrada  
cuelga del _bus principal_. Con un _Mayor_ `00` y un _Menor_ `02`. Si tuviesemos que  
expresarlo de forma gráfica:  

		|--+-- 00.00.0 NorthBridge  
			 |
			 |-- 00.02.0 VGA compatible controller  
			 
Pero qué pasa cuando hacemos halgo como lo siguiente?  

05:00.0 Ethernet controller: Realtek Semiconductor Co., Ltd. RTL8169 PCI Gigabit  

Estamos declarando la tarjeta de red, con su _própio bus_, con  
un _Mayor_ `05` y un _Menor_ `00`. Que todas las operaciones serán retransmitidas(broadcasted)  
a través de un _bus_ creado artificialmente/virtual/falso/creado por código.  

En este caso el árbol sería:  

		|--+-- 00.00.0 NorthBridge  
		|	 |
		|	 |-- 00.02.0 VGA compatible controller  
		|
		|--+--05.00.0 Ethernet Conttroller.  
		
Ahora bien, como sabemos que la mayoría de fabricantes, contruyen/desarrollan sus productos  
para _los Grandes_. Aunque _nosotros_ no queramos utilizar tal sistema operativo  
nos encontraremos, que el código -microcódigo de dispositivo, no está disponible, por que  
lo han _compilado/encriptado_ y sólo lo entiende la máquina.  

Ésto no es siempre así, pero en muchos casos es _exactamente_ lo que ocurre. Es en estos  
casos, cuando a algunos se nos empieza a llamar que si tramposos -hackers del inglés, etc.  
Pero aunque parezaca raro, si a alguno de _nosotros_, le apetece estrellar el dispositivo  
contra el suelo, está en su derecho democrático y constitucional, por que lo ha PAGADO.  

Es posible que haya alguno, que robe de la tienda el dispositivo. Pero en todo caso, es una  
excepción...  

... como decía, en ocasiones no quedan más narices, que _tramapear_ el sistema, para que el  
bendito dispositivo, funcione por la gracia de Dios. Entonces, ¿Qué pasará cuando _nosotros_  
hagamos lo siguiente?  


		cd /dev  
		mkdir input  
		mknod input/mice c 13 63  
		
Pues, pasará esto:  

		|--+-- 00.00.0 NorthBridge  
		|	 |
		|	 |-- 00.02.0 VGA compatible controller  
		|
		|--+--05.00.0 Ethernet Conttroller.  
		|
		|--+--13.64.0 keyboard controller  
		
		
ó alternativamente pasará esto:  


		|--+-- 00.00.0 NorthBridge  
		|	 |
		|	 |-- 00.02.0 VGA compatible controller  
		|	 |
		|	 +-- 00.13.63 keyboard controller  
		|
		|--+--05.00.0 Ethernet Conttroller.  
		

Si pasa lo primero, ocurre como en el en caso de la tarjeta de red.  
Si pasa lo segundo, estamos utilizando el bus principal, para controlar el teclado.  

¿Qué es lo mejor?, pués utilizar el bus del sistema, ya que el kernel de Linux, ha diseñado  
un sustancioso elenco de controladores de dispositivos para resolver este tipo de pormenores.  
Por eso, hackear si, pero sólo cuando no quede otra alternativa. La mayoría de dispositivos  
deberían funcionar con un _mínimo o nulo_ ejercicio de configuración.  

Queda otra alternativa, una tercera opción -que se me ocurra ahora, pero ya hablariamos del  
del gato de shrodinger o como dirían otros, la teoría de cuerdas basda en particularidades  
cuánticas. Es decir, que las dos cosas ocurran a la vez, o incluso más de dos o 100 veces  
al mismo tiempo.  

		00:1d.7 USB controller: Intel Corporation NM10/ICH7 Family USB2 EHCI Controller  
