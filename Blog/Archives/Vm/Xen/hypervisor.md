[Hypervisores](#i1)
[Instalación de Xen](URL)

[Anexo I](#i0001)
[Definiciones](#i88)
[Aplicaciones relacionadas](#i888)
[Referencias y agradecimientos](URL)






#### <a name="i1">Hypervisores</a> ####

_El hipervisor es un lugar donde no existe sistema operativo_. Un componente de código, que actúa como capa de virtualización, entre el hardware -la máquina y, el software -o el resto de aplicaciones necesarias para que todo lo demás funcione.

Un hipervisor es un _kernel_ -o núcleo de sistema operativo, especialmente diseñado para alojar otros sistemas operativos. Estrictamente hablando, el _hipervisor_ se compone de tres _elementos_ principales.

- El __hipervisor__, también llamado monitor de maquinas vituales.
- El kernel modificado, o __dom0__.
- __Utilidades y aplicaciones__, para _gestionar_ los supuestos sistemas operativos o máquinas virtuales, domU.

Diríamos entonces, que el _hipervisor_, es una _interfase_ entre los componentes de la máquina -el _hardware_ y, el sistema operativo, en este caso el _kernel modificado_, referido como __dom0__; puesto que de éste, partirán todas las comunicaciones.

El kernel, es la parte de software mínima, capaz de proporcionar los mecanismos necesarios con objeto de implementar el sistema operativo. Estos mecanismos incluyen la gestión del espacio de dirección a _bajo nivel_, gestión de hilos y la comunicación entre procesos(IPC).

Dentro del apartado de utilidades, requeridas para el correcto funcionamiento del _hipervisor_, se incluirían dependencias tales, como un gestor de arranque operativo, el paquete _iproute_ o un gestor de dispositivos(udev), entre otros.

Hay dos tipos de Hipervisores

![Hypervisores](../images/Qemu/400px-Hyperviseur.png)

__Tipo 1__

Este primer tipo, corre directamente sobre el _hardware_, para controlarlo y administrar los sistemas operativos invitados o _supuestos_. Es habitualmente utilizado el término _bare metal[f1](#f1)_ -del inglés, para referirse a ellos. 

__Tipo 2__

Un sistema operativo _invitado[f2]_, corre sobre el sitema anfitrión como proceso, igual que lo haría cualquier otra aplicación. 


> "xen contiene el código requerido para la detección  e inicialización de procesadores secundarios, _routing_ de interrupciones y ejecutar la enumeración del bus PCI."


#### <a name="i88">Definiciones</a> ####

<a name="f1">[f1]</a> __bare metal__: se refiere a una computadora ejecutando instrucciones, diréctamente sobre el hardware lógico, sin la intervención del sistema operativo. Correrá como proceso, sobre el sistema anfitrión(host).

<a name="f2">[f2]</a> __invitado__: sistema operativo invitado, también llamado _supuesto(guest)_, o máquina virtual. Podría tratarse de cualquier sistema operativo, corriendo sobre el sistema anfitrión.

__Emular__: es la capacidad de simular o replicar un componente de hardware. Qemu [f4](#f4), Quick Emulator, es un ejemplo de _emulador_. Está escrito en lenguaje de programación `C` y, es un _hipervisor hospedado_ de código libre. Permite que otros sistemas operativos corran sobre él, independientemente del sistema anfitrión y huesped.

__Paravirtualización__: Se trata de una técnica de virtualización, que no incluye emulación de hardware. Para que esto sea posible, los _supuestos_ __deberán ser modificables__ y hacer uso de _hiperllamadas_ especiales ABI [f3](#f3), en lugar de utilizar ciertas características propias de la arquitectura.

Mediante esta técnica se consigue mejorar el rendimiento de la máquina(VM), hasta niveles cercanos a un _sistema no virtualizado_.

__Sistema Nativo__: proporciona el código para la _emulación_ del hardware, en caso necesario. Por lo que el _supuesto_, podría ser cualquier sistema operativo sin modificar. Se espera un rendimiento inferior, al obtenido con técnicas de _paravirtualización_. En determinadas circunstancias, podría ser necesaria la virtualización del procesador.

__Virtualización__: el proceso de crear algo de forma _teórica_ en lugar de una versión "real" de algo. La definición es compleja en sí misma, sobre todo si hablamos de _software_, puesto que el software, no es algo tangible, no es un dispositivo.

__Capa de virtualización__: es una interfase, entre dos componentes. Esta "capa" de virtualización, difiere de un fabricante -o desarrallador a otro. Por ejemplo, __Qemu__ sitúa esta interfase entre el sistema operativo anfitrión y, las _aplicaciones_. __Xen__, sitúa la interfase, entre el _hardware_ y, el sistema operativo. Cada solución tiene sus _pros_ y _contras_. En un escenario perfecto, donde el procesador fuese _lo más potente posible_, el primer ejemplo sería el idóneo en todo caso. En un escenario con _recursos_ limitados, Xen conseguirá mejor rendimiento.

__Virtualizar el _kernel_:__ proceso por el que es convertido el kernel, en un hipervisor. Este proceso puede llevarse a cabo mediante la construcción de un nuevo kernel específico para la tarea, o bien cargando software _extra_ -un modulo, con las capacidades y limitaciones oportunas.

__VM__: máquina virtual -o virtual machine, deppendiendo de donde haya sido situada la capa de virtualización, el _gestor_ o hipervisor, estará integrado en la propia máquina virtual o fuera de la misma, corriendo como núcleo del sistema modificado.

__PVM__: máquina virtual _para-virtualizada_. El hipervisor _organiza_ los recursos del sistema -el _hardware_, premitiendo que el resto de sistemas operativos virtualizados, _accedan_ al los mismos, sin necesisdad de emular el dispositivo. Por ejemplo, Con Xen, el explorador de internet, podrá comunicarse directamente con la tarjeta de red.
Con Qemu, el explorador de internet, se comunicará a través de una tarjeta de red emulada.
> Es un ejemplo poco realista, tomese únicamente a efectos de entender el concepto.

__HVM__: máquina virtual _hardware_. Es este el ejemplo donde entraría Qemu. Es algo así como _crear un ordenador al completo_; sistema operativo, maquinaria y todo lo que tenga que tener. _Alquilamos_ una pequeña parte del procesador, para emular el componente mecánico -además del sistema operativo.

__VMM__: monitor de máquina virtual. El hiperisor, podría decir que "se ejecuta directamente sobre el hardware", aunque es preferible decir que "se comunica directmente con el hardware"; independientemente de como el _humano_, interprete la intrínsica ambiguiedad de su própia naturaleza. 

__Host__: anfitrión. 

__Dominio__: _domain_ en inglés. Término utilizado alternativamente, junto a _supuesto_ -o máquina virtual.

__dom0__: es un kernel modificado y, el primer dominio iniciado por Xen durante el arranque. Es en esencia el sistema operativo "anfitrión", junto a las aplicaciones y herramientas administrativas, necesarias para la gestión de las máquinas virtuales.
También llamado __servicio de cónsola__.

__domU__: es un dominio sin privilegios de acceso al _hardware_. Deberá correr un controlador de dispositivo, para que el _hardware_ multiplexado, sea compartido con otros dominios. 


### [Anexo I](i0001) ###

__¿Qué fué antes, el huevo o la gallina?__ En un escenario ideal -hablamos de un entorno de paravirtualización, el _hipervisor_, aparecerá como una "capa" intermedia entre la máquina -todos aquellos componentes que conforman el ordenador, etc, y las aplicaciones.

Desde esta perspectiva, uno se pregunta: por qué no suprimir el própio sistema operativo; quedándonos únicamente con aquellas partes necesarias para arrancar las VM. Esto significaría la ausencia total de un sistema operativo[f5] anfitrión. Por lo que en teoría, el arranque del sistema sería mucho más rápido y limpio.

Aún no hablamos de controladores de dispositivo, y mucho menos, de cualquier librería para poner en funcionamiento un entorno gráfico. De lo que se desprende que el `dom0` cargaría en un entorno sólo texto.

Pongamos como ejemplo, el código _mínimo_ de fabricante, desde el que podemos trabajar sobre los distintos dispositivos, através de la BIOS. Delante de la pantalla azul y blanco, es posible activar o desactivar distintos componentes. Hoy en día la mayoría de placas, permiten un arranque en red, esto es PXE.

Echando un ojo, al proceso de instalación de _Xen_, observamos que no estamos quitando componentes del sistema operativo, al contrario; añadimos el hipervisor, añadimos el kernel modificado, como nueva entrada en la secuencia de inicio del sistema y, añadimos herramientas varias, para la gestión de las máquinas virtuales.

GPT, GPT, GPT. Guid Partition Table. Hay que ver como arranca el sistema desde este entorno, por lo que un CITA REQUERIDA AQUÍ, va a tener que esperar turno. Pero imaginemos que aún estamos en 1995 DC. y solo existen rumores al respecto.

La instalación desde un LV, efectuada con anterioridad, nos conduciría a un menú minimalísta, en el que al menos, predecimos habrían dos entradas. El sistema operativo origen de la instalación y, la entrada añadida con el kernel modificado.

El buen tiempo acompaña a realizar el arranque del sistema, sobre una máquina que aún no tiene sistema operativo. Nuestro cliente, nuestra máquina. Esto quiere decir que el servidor anfitrión, o dador, está al corriente y funcionando.

Oímos en la radio a _perro libre_, hablándonos acerca del pronóstico del tiempo, convulso, inestable, frágil. Desde su refugio, advierte tomar precauciones externas. Así que resulta conveniente, planificar la ruta del día...

El objetivo es migrar el `dom0` tras haber compilado un núcleo, a prueba de controladores abusivos. Es posiblie afrontar la tarea de dos formas:

- Borrando la primera entrada, el "origen".
- _Migrando efectivamente_, el kernel modificado.

La primera opción, en ocasiones se antoja la apropiada, aunque no esta vez. No, porque significaría borrar manualmente el componente GNU y, a todas luces, resulta descabellado!

En cuanto a mover el `dom0`, junto al kernel -claro, etc, habrá que averiguar primero, si efectivamente es legal. Por lo que por el momento, habrá que seguir hablando de un tiempo aún no presente.

Sería posible cargar una especie de _gestor de renderización directa_, si el software de fabricante, opusiese cierta resistencia en cuanto a eludir la presentación de imágenes obligadas.

Pero esto significa, sintetizar el gestor -demasiado grande; o bien pasar las imagenes através del _almacén de páginas_, como hasta ahora.








__El sistema operativo anfitrión, es cargado bajo `dom0`__, es cargado por que si dibujásemos un mapa de la RAM en ese momento, el primero de la lista sería el `dom0` y de él partiría el SO.









#### <a name="i888">Aplicaciones relacionadas</a> ####

Xen, Xen Server, VMware Server, VMware Sphere, z/VM, Oracle VM, Sun xVM Server, Virtual Server, VMware ESX Server, VMware Fusion, Hyper-V, Qemu.

#### <a name="i99">Referencias y agradecimientos</a> ####

<a name="f3">[f3] ABI - ver [siglas](www.territoriolinux.net/TerritorioLinux/siglas.html)</a>



[f5](f5) ausencia total de sistema operativo: tal y como lo conocemos hasta el momento, es decir, el kernel y GNU. Dicho así de rápido suena hasta mal, pero no pretendo deshacerme de ningúna de las partes.


Hypervisor [wikipedia](https://en.wikipedia.org/wiki/Hypervisor).
Qemu [wikipedia](https://en.wikipedia.org/wiki/QEMU)
Xen [wikipedia](https://en.wikipedia.org/wiki/Xen)
Microkernel [wikipedia](https://en.wikipedia.org/wiki/Microkernel)

__Administración Avanzada de sistemas informáticos__ Editorial Ra-Ma&reg; por:
	Julio Gómez López, Francisco Gil Montoya, Eugenio Sánchez Villar, Francisco Mendez Cirera


<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>

siguiente f5

