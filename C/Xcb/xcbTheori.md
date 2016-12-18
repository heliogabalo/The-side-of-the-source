## __KCB__ Basic knowledge

- An X app first needs to open the connection to the X server using:

  `xcb_connect()`

      // if NULL, uses the Display enviroment variable!!
      // return the screen number of connection; can provide NULL if don'r care.
      `xcb_connection_t *xcb_connect(const char *displayname, int *screenp);`

- To close a connection, it suffices to use:
    `void xcb_disconnect(xcb_connection_t *c);` ejem: `xcb_disconnect(connection)`

#### Checking basic info about connection
This are such data to know the kind of screen we are working on. We get that
info from a `struct` like this:

    `typede struct{
        xcb_window_t    root;
        xcb_colormap_t  default_colormap;
        uint32_t        white_pixel;
        uint32_t        black_pixel;
        uint32_t        current_input_masks;
        uint16_t        width_in_pixels;
        uint16_t        height_in_pixels;
        uint16_t        width_in_millimeters;
        uint16_t        height_in_millimeters;
        uint16_t        min_installed_maps;
        uint16_t        max_installed_maps
        xcb_visual_t    root_visual;
        uint8_t         backing_stores;
        uint8_t         save_unders;
        uint8_t         root_depth;
        uint8_t         allowed_depths_len;
      } xcb_screen_t`

We could retrieve the first screen of the connection by using:

  `xcb_screen_iterator_t xcb_setup_roots_iterator(xcb_setup_t *R);`
> see retrieve_screen on .

#### El modelo cliente servidor
> Una cosa es como son las cosas y, otra distinta es como se _hacen_.

Uno de los criterios mas importantes del _servidor de las X_ es su __flexibilidad__.
Con esto en mente, se tomó la decisión de separar el sistema en dos partes. El cliente
decide _que hacer_ y, el servidor es quien realmente dibuja en la pantalla y lee las
entradas de usuario, para depués enviarlas al cliente para su procesado.

Este modelo, es __opuesto__ a como normalmente trabajaría un cliente/servidor de cualquier
otro tipo. En este caso, el _cliente_ reside junto a la máquina, el cuál es controlado
por el _servidor_; mientras que un _cliente_ puede estar corriendo en una máquina remota,
el servidor controla la pantalla, el ratón, teclado...

Un cliente podría conectar al servidor, solicitar a éste que dibujase una pantalla
-o varias-, y requerirle después, que envíe las entradas de usuario a cualquiera de estas
ventanas.
Cuando una entrada es enviada desde el cliente a cierta ventana, el servidor envía
un mensaje al cliente controlando esa ventana para procesarla. El cliente decide que
hacer con esa _entrada_ y, envía la respuesta al servidor par dibujar la ventana.

Toda la sesión es negociada mediente el protocolo de mensajes _X_. Originalmente Este
protocolo fue concebido para tabajar con la _serie_ __TCP/IP__, más tarde fue extendido
para permitir a clientes _corriendo_ en máquinas locales, un más optimizado acceso al
servidor. Debe mencionarse que, un mensaje con el protocolo _X_ podria ser de varios
cientos de _KB_ de tamaño; e igualmente estar usando la memoria compartida, zócalos de
dominio tipo _Unix_, etc.

#### GUI: modelo asíncrono de programación.
Una interfase gráfica de usuario(GUI), utiliza habitualmente un modelo asíncrono
de programación, también conocido como _programación de evento conducido_. Esto
significa que, mayormente el programa presenta un estado de reposo, esperando Eventos
enviados por el servidor, y actuar entonces, contra esos eventos.
Un evento prodría ser: _el usuario a pulsado `1`, en la coordenada `(x,y)`_, o _la
ventana que controlas necesita ser redibujada_.
Para que un programa pueda actuar/reflejar las entradas/acciones de usuario o refrescar
las solicitudes, necesita manejar cada evento en un breve periodo de tiempo -ejem. 200ms
como regala orientativa.

El aspecto de una aplicación gráfica, podría ser el siguiente:
  1. Inicialización de rutinas.
  2. Conexión al servidor.
  3. Inicialización relacionada con _las X_.
  4. Mientras no termine:
    1. Recivir próximo evento desde el servidor X.
    2. Manejar el evento, enviando peticiones de dibujo al servidor.
    3. Si el evento es mensaje de salida, salir del bucle.
  5. Cerrar conexión con servidor X.
  6. Operaciones de limpieza.

#### Nociones básicas de XCB
XCB ha sido creado para eliminar la necesidad de implementar la capa de protocolo X.
Esta libreía, confiere al progrma un acceso de _muy bajo nivel_ a cualquier servidor X.
Desde la estandarización del protocolo, un cliente usando la implementación de _XCB_,
puede hablar con cualquier servidor X -por supuesto, lo mismo para Xlib.

##### 1. La conexión _X_.
Lo más destacable usando _XCB_ es la conexión X. Es una estructura representando
la conexión que ha sido establecida con un servidor _X_. Ésta, esconde la cola de
mensajes que llegan desde el servidor y, la cola de peticiones pendiente, desde nuestro
cliente hacia el servidor.
En _XCB_, esta estructura se llama `xcb_connection_t`. Siendo análoga a _Xlib Display_.
Cuando abrimos la conexión al servidor, la librería devuelve un puntero a esa
estructura. Después, suministramos el puntero a cualquier función _XCB_ que debería
enviar mensajes al servidor o recivir mensajes _desde_ el servidor.

##### 2. Peticiones y respuestas: mejoras sobre Xlib.
Para solicitar información desde el servidor, se necesita hacer una petición y esperar
la respuesta. Con _Xlib_, esta tarea se lleva a cabo automáticamente; Xlib bloquea el
sistema, envía la petición, espera la respuesta del servidor _X_ y, desbloquea.
Esto resulta molesto, especialmente si se hacen muchas peticiones al servidor X.
De hecho, _Xlib_ no tiene que esperar a la respuesta antes de hacer la siguiente(debido
a los bloqueos). por ejemplo; dada la línea de tiempo `N=4 peticiones/respuestas Xlib`,
con una latencia de ida y vuelta que es 5 veces mayor que el tiempo requerido para
leer o escribir la peticion/respuesta __T_write/T_read__:

    w-----RW-----RW-----RW-----R


  * W: escribiendo peticiones.
  * -:Paralizado, esperando datos.
  * R: Leyendo respuesta.

El tiempo total es `N * (T_write + T_round + T_read)`.


#### Eventos
En un programa bajo las _X_ **_todo_** es un evento, incluso en una ventanas que
fue escondida, si se _expone_, el servidor _X_ manda un _evento_ para hacer conocer
al programa, qué parte de la ventana debe volver a redibujarse.
La entradas de usuario -pulsación de tecla, movimiento de ratón, etc- son recividas
como conjunto de eventos.
