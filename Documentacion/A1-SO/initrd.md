## Disco Ram de inicio

_Extraido de wikipedia:_

En computación, `initrd`(disco de inicio Ram) es un esquema para cargar 
temporalmente en memoria, el sistema de ficheros _root_, el cuál podría ser
utilizado como parte del proceso de arranque de _Linux_. 

Referidos a métodos distintos de conseguir ésto `initrd` e `initramfs`, son
comunmente usados, durante los preparativos de inicio de sistema y, que 
finalmente permitirán al _SO_ poder montar el sistema de ficheros `root`
definitivo.

## Antecedentes
Muchas de las distribuciones _Linux_, hacen uso de un _núcleo(kernel)_, 
genérico, donde los desarrolladores de la própia distribución siguen unas
_directrices_ acorde al ideario interno de tal distribución.

Esto significa, que aunque se trate de minimizar la carga omitiendo distintos
módulos, durante el tiempo de compilación del nucleo, al ser una imagen 
_pre-determinada_, el núcleo, seguirá siendo un componente muy grande.

Algunos usuarios y administradores, considerán este tipo de _paquetes_, 
_pre-definidos_, un agujero negro, en cuanto a seguridad se refiere y, los
más puristas, acabarán por descargar la fuente del núcleo y compilando
únicamente, aquellos módules que vallan a ser utilizados realmente.

Por ejemplo, se sabe que el sistema tiene una tarjeta gráfica tipo _NVidia_,
¿para que diablos necesita el usuario, los drivers de otra GPU AMD? sería
algo así como comprarse un Wolkswagen Polo, y después comprar una llantas
para una Ford Pick'up!

A menos que seamos unos mecánicos, _furiosos_, tiene el mismo sentido que
tirarse de una bicicleta en marcha. 

Dicho de otra forma, los desarrolladores de una distribución _Linux_ 
específica, desconocen, quien va a descargar su sistema operativo, o
que ordenador a comprado el usuario o, para qué lo va a utilizar.

De esta forma, se compila un núcleo genérico, que sea capaz de llegar
a un mallor número de usuarios, con un mínimo proceso de configuración.

## Funcionamiento

El gestor de arranque, leerá el núcleo junto a un sistema de ficheros 
inicial llamado raíz(root), -como una imágen en memoria, y después activará
el núcleo, pasando a la memoria, la dirección de la imagen.

- Carga estática
- Carga dinámica
- initrd
- initramfs
- Gestor de arranque




















