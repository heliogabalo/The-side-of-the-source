[Referencias y agradecimientos](#i99)


## Dac ##

Conversor de señal digital a analógica. __Dac__, es un sistema capaz de convertir una señal digital a otra analógica. En el extremo opuesto, el __ADC__ llevará a cabo la función contraria.

En una llamada telefónica, la voz del usuario es convertida a una señal eléctrica analógica, por medio del micrófono del aparato, después, la señal es convertida a digital a través de un conversor ADC. El flujo de datos digitales, es entonces dividido en _paquetes de red_, pudiendo ser enviados junto a otros _paquetes_, no necesariamente audio.
Los paquetes son entonces recibidos en la destinación, pero cada paquete podría o no, tomar una ruta completamente diferente, incluso llegando a su destinación en el tiempo esperado.
Los datos de voz digital, son extraidos de los paquetes y ensamblados en una señal digital. Un DAC, vuleve a convertirlos en señal eléctica analógica, el cuál controla el amplificador, que a su vez, controla los altavoces y, finalmente producen el sonido.

En la mayoría de placas base, este dispositivo es embebido en la misma, junto al resto de chips, conformado lo que conocemos como _chipset_ -o conjunto de chips. 
Tanto los amplificadores, como los altavoces o en cualquier caso, el oído humano, son incapaces de traducir o interpretar esta señal digital, por lo que es indispensable tal dispositivo, con el propósito de _traducir_ el _conjunto de ceros y unos_ y, convertirlos en "algo que tenga sentido".

Aunque es cierto que todos los _DAC_ tienen el mismo propósito, no todos los _DAC_ consiguen el mismo resultado final. Esto es así, debido a distintos factores; las _piezas_ que constituyen el dispositivo, su calidad y, otros.

Convertidores más _sencillos_, podrían introducir ruido innecesario, durante la reproducción, debido al diseño y calidad de la circuiteria -sin mencionar la distorión extra añadida por fluctuaciones eléctricas (jitter).

Las variaciones -_el jitter_, son definidas como _errores de sincronización digital_. La precisión, en tiempo, del flujo digital es vital para conseguir un mejor rendimiento, por lo que un _pobre diseño_ en sus componentes, determinará un peor rendimiento.

Esta problemática generada por la distorsión, puede suceder en el momento que una señal digital deba _viajar_ a través del circuito de placa. Siendo __particularmente__ problemático, cuando la señal es transferida __entre dispositivos__.

Los equipos DAC, de alta fidelidad -_HI-FI_, acostumbran a tener _relojes digitales_ con mayor precisión, que los encontrados en la mayoría de PC's, por lo que la conversión de señal, se llevará a cabo con mayor _fidelidad_.

Esto es la teoría. Ahora bien, en mi opnión y, dado que este es un blog dedicado al _Game_, o __videojuego__, deberíamos tomar una perspectiva en este sentido. Por lo tanto, estas son las opciones:

- La segunda opción, es instalar una segunda GPU, en SLI configurando el driver adecuado.
- La tercera opción, es comprar una tarjeta de audio, con capacidades o características específicas, mas adecuadas a nosotros, los _gamers_.

En cualquier de los casos anteriores, hay que tener en cosideración una cosa, por encima de todo lo demás. Cuando hacemos una instalación en SLI, habrá que asegurarse que el bus de la PCIe16(x16) no sea compartido con el bus del segundo zócalo, de lo contrario, estaremos _capando_ el ancho de banda del bus, a la _velocidad límite_ de la segunda PCIe, que podría ser (x8), (x4) o lo que fuese.

Por lo que, uno fácilmente deduce que ante la alternativa de comprar una segunda GPU y liarla en la instalación; es mejor comprar directamente una tarjeta de audio e instalarla lo más alejada posible de la gráfica -_en mi opinión_.

He dejado a propósito, la primera opción para el final, por que quería resaltar que el _orden_ en `$miLista` de opciones, __no es lo importante__, si no la opción en si misma...

La primera opción, es utilizar el DAC, de la própia placa -que en el caso de las _Gamers_, habría que matizar bastante más. Así que dejaré el comentario para otra ocasión y, os invito a que sintoniceis con el _Taller Territoriolinux_, para leer la próxima semana acerca del __Gestor de eventos de entrada y salida de dispositivo, KVM__, desde una perspectiva de servidor. _The rackerMan_.


### <a name="i99">Referencias y agradecimientos</a> ###


<a href="https://en.wikipedia.org/wiki/Digital-to-analog_converter">DAC -- Wikipedia</a>
[what hi-fi](https://www.whathifi.com/advice/dacs-everything-you-need-to-know)

P.D. `googleToSoundCards()` y pasarle los argumentos que querais, que hay suficientes métodos de sobrecarga.
