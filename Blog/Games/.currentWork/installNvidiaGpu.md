Tanto si es para investigación o como entretenimiento, instalar una nueva GPU dará un empujón al rendimiento de la computadora, además de proporcionar otras funcionalidades a la placa. Esta guía de instalación, utiliza la rama __Fedora 28__ y, repositorios de terceros, para instalar los controladores de NVIDIA. 

Conduce al lector, através de la instalación del _software_ y _hardware_; cubre cualquier aspecto necesario para poner en funcionamiento la tarjeta NVIDIA. El procreso trabaja sobre ordenadores con UEFI activado y, sobre cualquier tipo de _gráfica_ moderna de NVIDIA.

La guía enfatiza los siguientes materiales:

*		Una máquina con soporte UEFI. El comando `dmidecode -t 0` arroja sobre la cónsola la información para comprovarlo. Habrá que buscar si aparece: __UEFI supported__. De cualquier otra forma, aunque es posible _actualizar_ ciertas máquinas y darles soporte UEFI, no es recomendable, al ser un proceso delicado.
* Una moderna tarjeta gráfica NVIDIA.
* Una fuente de alimentación, que cumpla los requisitos de conexiones y, potencia -vatios, para la tarjeta NVIDIA. Ver la sección _Hardware y modificaciones_ para más detalles.
* conexión a internet.
* Fedora 28.

El ejemplo de instalación utiliza:

* Un computador de sobremesa, Dell Optiplex 9010.
* Tarjeta gráfica NVIDIA GeForce GTX 1050 Ti XLR8 Gaming Overclocked Edition 4GB GDDR5 PCI Express 3.0.
* Con objeto de hace coincidir los requisitos de energía de la GPU, la fuente de alimentación fue cambiada por una EVGA – 80 PLUS 600W ATX 12V/EPS 12V. La PSU está 300W por encima del mínimo recomendado, aunque con satisfacer el mínimo recomendado es duficiente, en la mayoría de casos.
* Fedora 28, por supuesto!

### _Hardware_ y modificaciones ###


__PSU__

Abrir la caja de la torre, para comprobar los datos impresos en la PSU. Comprobar igualmente la documentación de la GPU NVDIA y, comparar el mínimo recomendado en vatios. Mirar también, si la GPU requiere algún tipo de conexión adicional, como un conector de _6-pins_. En muchos casos la GPU, toma la energía directamente de la placa, pero algunas, piden _chicha extra_. Será necesario _actualizar_ la PSU si:

- el mínimo sugerido no coincide con el desarrollo máximo de la fuente de alimentación.
__nota__: de acuerdo con algunos fabricantes de tarjetas NVIDIA, sistemas preconfigurados podrían requerir más o menos, energía de la especificada en la tabla técnica de la PSU -es el caso de la fuente de alimentacion marca Tacens radix, esto tiene que ver con el valor al _factor corrector de potencia_ que asume el fabricante para la _fuente_. En el caso de la Tacens, se estima un valor nominal mayor, del que realmente es capaz de desarrollar la PSU. Esto no es malo ni bueno, hay que leer más! En la tabla de características, se lee claramente que el desarrollo de trabajo para el doble canal +12V, es de 504W para un total nominal de 600W. Resumiendo, la fuente no va más allá de los 504W por que el resto de energía se disipa sin alcanzar un trabajo efectivo.

Comentar de igual forma, que deberíamos _tocar a tierra_, antes de _meter mano_ a algún componente, -fuera anillos, relojes, etc, y, asegurarnos que la carcasa de la PSU, va a caber dentro de nuestra _caja_.


__CPU__

Aunque instalar una GPU NVIDIA de alta calidad, es posible en máquinas viejas, un procesador lento o -de alguna manera, _estropeado_, podría producir un _cuello de botella_ en cuanto al funcinamiento de la GPU. Para detectar el impacto negativo sobre una máquina, [click aquí](http://thebottlenecker.com/). Es importante conocer las características del procesador, para evitar parear una GPU de alto rendimiento, con un procesador que _no de la talla_! Considerar _actualizar_ la CPU.


__Placa Base__

Antes de proceder, hay que asegurar que la placa base, sea compatible con la GPU escogida. La gráfica debería ser insertada en el zócalo PCI-E x16, cerca del difusor de calor. Asegurando que la configuración contiene espacio suficiente para la GPU. 
En adición, nótese que las GPU's de hoy en día emplean tecnología PCI-E v3.0. Aunque estas GPU's, funcionarán mejor sobre zócalos PCI-E v3.0, no deberían sufrir significativamente, sobre versiones de zócalo anteriores.

1. Lanzar un terminal y, actualizar el _gestor de paquetes_:

		$ sudo dnf update

2. A continuación reiniciar el sistema, con un simple:

		$ reboot

3. Tras el reinicio, instalar los repositorios de Fedora 28 Workstation:

		$ sudo dnf install fedora-workstation-repositories

4. Activar el repositorio del controlador NVIDIA:

		$ sudo dnf config-manager --set-enabled rpmfusion-nonfree-nvidia-driver

5. Reiniciar nuevamente

6. Verificar que el repositorio ha sido añadido, mediante el comando:

		sudo dnf repository-packages rpmfusion-nonfree-nvidia-driver info

Si las distintas herramientas y sus respectivas especificaciones para NVIDIA, son cargadas, proceder con el siguiente __paso 7__. Si aparecieron errores, al añadir el nuevo repositorio, repetir el proceso.

7. Conectar a internet, abrir la aplicación de la GPU e identificarse si procede. Clic sobre 
<kbd>Add-ons</kbd> > <kbd>Hardware</kbd> > <kbd>Drivers</kbd> > <kbd>NVIDIA Linux Graphics Driver</kbd> > <kbd>Install</kbd>.

En este punto volveríamos a reiniciar el sistema.

8. En el siguiente paso, desde la barra lateral > <kbd>Show Applications</kbd> y, abrir la entrada añadida > <kbd>NVIDIA X Server Settings</kbd>. Debería abrirse una interfase gráfica, apareciendo en ésta una _caja de diálogo_ con el siguiente mensaje:

![](URL)

Aceptar la advertencia de la aplicación, pero antes de hacerlo, comprobar que tenemos  a mano la GPU NVIDIA y, se está preparado para la instalación. Téngase en consideración, que al _abrir_ <kbd>nvidia xconfig</kbd> como usuario __root__ y, apagar el sistema sin instalar inmediatamente la GPU, podría causar drásticos daños. Incluso provocar que la computadora arrancase, forzando al usuario a reparar el sistema através de la _pantalla de reinicio_. Una nueva instalación de Fedora, __podría__ solucionar el problema, aunque cabe la posibilidad de otros efectos peores.

Estando preparado para proceder, entrar el comando:

		sudo nvidia-xconfig
		
En caso de solicitar el sistema, alguna descarga, aceptarla y proceder.

9. Una vez haya sido completado el proceso, cerrar todas las aplicaciones y apagar el ordenador. Desconectar el cable de alimentación -para asegurarnos que la RAM es vaciada al completo y, pulsar el boton de encendido, para drenar cualquier remanente de energía residual, con objeto de protegernos a nosostros mismos, de descarga eléctrica. Si la PSU dispone de interruptor de _contacto_, debería ser accionado -apagar (to switch off).

10. Finalmente, instalar la tarjeta gráfica. Retirar la vieja GPU e insertar la nueva _gráfica_ NVIDIA, en el zócalo apropiado PCI-E x16, con los ventiladores hacia abajo. Si no hubiese espacio para acomodar[f2] la GPU en tal posición, colocar la tarjeta con los ventiladores hacia arriba, si es que es posible.
Cuando la instalación haya concluido, cerrar la carcasa, conectar la PSU y, encender la computadora. Debería arrancar satisfactoriamente.

__Nota__: para desactivar el repositorio del controlador NVIDIA utilizado en la instalación, o desactivar los repositorios de _fedora workstation_, consultar la página _Fedora Wiki_.


### Verificación ###

1. Si la gráfica está conectada al monitor, y funcionando corecctamente, entonces el controlador también ha establecido una conexión apropiada.

Para revisar la configuración o verificar que el controlador está funcionando -en el caso de tener dos GPU's instaladas en la placa, abrir nuevamente la aplicación <kbd>NVIDIA X Server Settings</kbd>. En esta ocasión, no aparecerá pregunta alguna, o mensaje de error; la información relativa a la configuración de _las X's_ y de la GPU, estará disponible. Ver captura de pantalla más abajo.

![alt text][image label]

Mediante ésta aplicación, es posible _alterar_ el archivo de configuración de _las equis -El servidor Xorg_, monitorizar el rendimiento de la GPU, velocidad de reloj e información térmica.

2. Para comprobar que la nueva tarjeta funciona a su capacidad, es necesaria una prueba de rendimiento de la GPU. <kbd>GL Mark 2</kbd>, una herramienta comparativa que proporciona información de _almacenamiento[f1]_, _construcción_ e _iluminación_, texturizado, etc. <kbd>GL Mark 2</kbd> guarda _frecuencias de muestreo_ para una gran variedad de pruebas gráficas y, arroja una puntuación de rendimiento total; llamada _glmark2 score_.

__nota__: `glxgear` únicamente prueba el rendimiento de la pantalla o monitor; no la tarjeta gráfica en sí misma. Usar <kbd>GL Mark 2</kbd> en su lugar.

__Utilización__:

1. Abrir una cónsola y cerrar todas las demas aplicaciones abiertas.
		
2. 
		$ sudo dnf install glmark2

3. 
		$ glmark2

4. Permitir que concluya el _test_, para un mejor resultado. Comprobar si la _frecuencia de muestreo_ coincide con la esperada para la GPU. Se es preciso verificación adicional, consultar la _web_ para determinar si otras comparativas `glmark2` han sido publicadas, para la tarjeta en cuestión. Comparar puntuaciones a efectos de evaluación de rendimiento.

5. Si los resultados están por debajo de lo esperado, considerar causas potenciales:
	* ¿El cuello de botella es inducido a causa del procesador?
	* ¿Otros problemas?
	

### Referencias y agradecimientos ###

* [How to benchmark your GPU on Linux](URL)
* [How to install a graphics card](URL)
* [The Fedora Wiki Page](URL)
* [The Bottlenecker](URL)
* [UEFI](siglas.html)



[f1] __nota d.t.__: buffering, almacenaje, almacenamiento, referido a una "memoria" de algún tipo -habitualmente en la RAM. En este caso podría referirse a un _bufer_ de intercambio gestionado por la GPU.

[f2] __Nota d.t.__: En <territoriolinux.net> no hemos probado todas las gráficas, en todas las placas, obviamente desconocemos si existe algún fabricante que construya tarjetas que puedan colocarse indistintamente, en una posición u otra. Esto es importante por que forzar la inserción de la tarjeta, es algo que __no debe hacerse jamás__. Pero el apunte nos ha resultado muy interesante, puesto que nos __dirige__ hacia una perspectiva de __ensayo__, donde participan __otros componentes__!




__Autor__:  Justice del Castillo

Artículo original: __Install and Nvidia GPU on almost any machine__
<https://fedoramagazine.org/install-nvidia-gpu/>
