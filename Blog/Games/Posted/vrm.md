* [Módulo regulador de voltaje](#i1)
* [Contenido](#i2)
* [Prólogo](#i3)
* [Identificación del voltaje](#i4)
* [Ver también](#i5)
* [Referencias y agradecimientos](#i99)

***************

#### <a name="i1">Módulo regulador de voltaje</a> ####

Módulo   regulador de voltaje, __VRM__. Otras veces   llamado,  
PPM(_processor power module_). 

_Mecanismo corvertidor[f1]_ que proporciona al _microprocesador_  
el voltaje adecuado; conviertiendo `+5 V` o `+12 V` a voltajes  
menores tensiones, requeridas por la CPU. Esto permite a proce-  
sadores con distintos _requisitos de suministro_, ser montados  
en la misma _placaBase_.


#### <a name="i2">Contenido</a> ####

1. Prólogo
2. Identificación del voltaje
3. Ver también
4. Referencias y agradecimientos


#### <a name="i3">Prólogo</a> ####

Algunos módulos reguladores de voltaje, están soldados a   la  
_placaBase_, mientras que otros son instalados en un   zócalo  
especialmente diseñado , para alojar reguladores de   voltaje  
_modulares_. 

Algunos   procesadores -como los Intel Haswell,   incorporan  
componentes   para la regulación del voltaje,  en la   misma  
_carcasa_ del procesador, en lugar de tener el VRM como parte  
de la _placa_; este tipo de diseño, brinda cierto nivel   de  
simplificación, sobre _regulaciones de voltaje_ complejas, que  
involucran   distintos suministros de voltaje a la CPU y,   al  
encendido   y apagado dinámico, de las diferente areas de   la  
misma.  

Un _módulo de voltaje ingreado_ -`on-package` o `on-die`,  es  
referido como FIVR[f2] o IVR.

La mayoría de CPUs modernas, requieren menos de `1.5 V`, puesto  
que los diseñadores de procesadores, tienden a utilizar menores  
tensiones en el _núcleo_ del procesador; esto ayuda a reducir la
pérdida o disipación de energía.  
Es   a menudo especificado por el TDP,  -o diseño térmico   de  
energía,   que sirve como _valor nominal_, en el diseño   de  
sistemas de refrigeración de la CPU.

Algunos reguladores de voltaje, proporcionan un suministro fijo  
de voltaje al procesador, pero la mayoría de ellos _determinan_  
el  voltaje que necesita el mismo.  Actúan como un   regulador  
ajustable variando contínuamente. 
En particular, aquellos VRMs soldados a la _placa_,  detectan  
las variaciones, de acuerdo a la especificación de Intel.

Las unidades de procesamiento gráfico modernas GPUs,  también  
utilizan el VRM, debido a las _altas tensiones[f3]_ y, a  los  
requisitos de energía. Estos VRM, generan cierta cantidad  de  
calor, por lo que necesitan un _disipador de calor_, separado  
de la GPU.


#### <a name="i4">Identificación del voltaje</a> ####

El   microprocesador,  comunica el suministro del   voltaje  
adecuado al VRM, durante el _arranqque_. A través de un número  
llamado VID -identificador de voltaje. Inicialmente el   VRM,  
proporciona suministra un voltaje _estandar_ a la _lógica_ vid,  
que es la parte del procesador, encargado de enviar el VID al  
VRM. 

Cuando el VRM recibe el VID, identificando el suministro de  
voltaje requerido, empieza a actuar como _regulador de voltaje_  
proporcionando el voltaje necesario, de fomar constante.

En   lugar de tener una fuente de alimentación, genera   un  
voltaje fijo. La GPU, utiliza un conjunto de señales digitales  
-líneas VID,  para instruir al convertidor de energia de   la  
_placa_ con el nivel de voltaje deseado. Esto proporciona 
cierta flexibilidad,   posibilitando el uso de la misma fuente  
de alimentación, para CPUs con distintos valores nominales en  
el   suministro de voltaje. Esto reduce el consumo de energía,  
durante períodos de _inactividad_, por medio de la reducción  
del suminitro de voltaje.

Por   ejemplo, una unidad de `5-bit` VID, _entregaría_   como  
maximo   unad de 32 (2 potencia de 5) distintas salidas   de  
voltaje. Estos voltajes son habitualmente  -pero no siempre,  
espaciados de forma uniforme, dentro de un rango.  
Algunas _palabras de codigo_, podrían estar reservadas, para  
funciones especiales, como apagar la _unidad_, por lo que una  
unidad `5-bit` VID, podría tener menos de 32 niveles de voltaje  
de salida. 

Cómo el código numérico _hace el mapeado_ del suministro   de  
voltaje, es concretado en _las tablas_ proporcionadas por el  
fabricante de componente. Desde 2008, _el VID_ aparece en `5-`,  
`6-` y `8-`, variedades distintas. La mayor parte, aplicadas a  
módulos de salida entre `0.5 V` y `3.5 V`.














#### <a name="i99">Referencias y agradecimientos</a> ####

[Wikipedia](https://en.wikipedia.org/wiki/Voltage_regulator_module)

[f1] nota d.t. buck: 1. chico, colega. 2. un dolar 3. el montón  
de "pasta" que _atesora_ un jugador de _poker_ antes de apostar.  

[f2] ver [siglas](www.territoriolinux/TerritorioLinux/siglas.html)

[f3] altas tensiones, habla de la tensión que llaga a la fuente de 
alimentación, desde la red doméstica o en una ofician -en todo caso.
Esto es 220v, habitualmente. La fuente de alimentación lleva a cabo 
la transformación de voltaje y, es cuando se empieza a hablar de los
`+5 V` `+12 V`. Aquí no se utilizan pértigas ni guantes de _latex_.




