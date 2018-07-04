***************

NUMA
Así, podemos decir que estas operaciones de entra/salida serán delegadas a un _procesador externo_. Significando esto, que el procesador de nuestro equipo, no tendrá que soportar la carga de trabajo producida por dichos eventos; junto a la consecuente _liberación_ de memoria caché/s del procesador. 

RAM <--> HDD
Como podemos saber si un equipo, tiene una reserva de memoria suficiente, para alojar remotamente nuestra aplicación?

Comprobando el dato, Hay muchas maneras de hacerlo. Una aproximación teórica, que prediga este dato, es tan simple como suponer que cierta aplicación está ya en ejecución en el sistema. Pero esto no resuelve el problema, por que podría ser que la aplicación estuviese en ejecución. Lo que significa que la memoria que necesitamos está en uso. Esta aproximación no vale. Pero podría valer, si la aplicación inicia la reserva de memoria, pero no la utiliza en su totalidad.

Otra, podría ser machacando el buzón de correo electrónico de alguien, con correos falsos -o adoptando un mecanismo para falsear correos legítimos(invasión del almacén de claves del explorador!!), hasta llegar a sumar entre todos ellos, el tamaño de memoria que necesitamos. Es una aproximación tambien teórica, puesto que el usuario no abrirá todos los correos al mismo tiempo.
Pero ya tenemos un mecanismo -con un registro cuantificable, que además está conectado a internet. Las cookies del explorador web. Este registro de cookies es sincronizado, cada vez que abrimos una página en el explorador. Actualizando continuamente la info. 

Analicemos un momento el comportamiento del explorador; abrimos 8 o 18 páginas, pero sólo estamos leyendo una al mismo tiempo:

Datos que podemos deducir:

- El tamaño del archivo, _que es la página_.
- Que el _registro de cookies_ hace referencia a esas páginas.
- Que el archivo en cuestión, ya ha sido descargado a nuestro equipo. Mientras no borremos el historial, la página estará en nuestro equipo. Es toes demostrable cerrando la página, y briéndola de nuevo. Cargará mucho más rápido.

***************

