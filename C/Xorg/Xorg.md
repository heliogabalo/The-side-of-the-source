## X.org, el servidor de las _equis(X)_.

Separa la implementacion de la _X_ en dos partes conectadas por una interfase
con más de 25 años de madurez. A tener en cuenta:
  - Cliente.
  - Servidor.
> Keith Packard, "el Linus Torvald de las _X_".

Hay una clara diferenciación entre el _código base_ que conforma ambas partes.

La siguiente es la estructura del sistema de ventanas _X_:  
[estructura-X](Images/xorg.svg)

- Intraestructuras relacionadas:

  __Cliente__
  * Pango - motor de texto(librería).
  * Cairo - dispositivo gráfico usado para crear imágenes de alta calidad en
  formato _pdf(y otros)_.
  * Kit de desarrollo - __Xlib/Xcb__

  __Servidor__
  * __DDX__ - Controlador de Dispositivo Dependiente de las _X(DDX)_. El cuál
  hace las inicializaciones, controla el dispositivo y lleva a cabo la renderi-
  zación en __2D__. Cada Controlador de dispositivo(driver) tiene una pequeña
  parte de código para hacer la abstracción en __3D/DRI__.
  * __DIX__ - Controlador de Dispositivo Independiente de las _X(DIX)_. Inter-
  actua con el cliente e implementa el software de renderización. Básicamente
  todo en el servidor, excepto el directorio _hw/_(chroot/initframs?). El
  bucle principal y la entrega de _evento_ es parte de _DIX_.

  __Comunes__
  * Mesa(OpenGL).
  * Gallium - Controlador genérico(que debe ser la implementacion de _Amd_ en _Linux_).

  __Extensiones__  

  * _XRandr_- Protocolo. Extensión para redimensionar, rotar, reflejar.
  * _Xinput_- Utilidad para listar dispositivos de entrada. NOTA: __MPX__
  * _Render_- Extensión que introduce la composición de imágenes digitales como
  fundamento de un nuevo modelo de renderización en el sistema de las _X_.
  * _GLX_   - Extensión del sistema de ventanas de las _X_, el cuál preoveé al
  mismo, de una interfase entre _OpenGL_ y las _X_.


---
#### MPX
Es una implementacion en el Servidor _X_ para soportar múltiples dispositivos
funcionando al mismo tiempo, ejem. _teclado, ratón, panel de toque!_. Es una
funcionalidad _relativamente_ reciente en las _X_.

Un dispositivo físico es un _dispositivo esclavo_, no tiene cursor y, únicamente
envía _XI_ (eventos de entrada).

Su esquema o estructura se resumiría de la siguiente manera:
  - MD - Dispositivo Maestro(Master Device). El cuál viene siempre asociado a
  un _par_; el puntero y el dispositivo.
  - SD - Dispositivo Esclavo(Slave Device). Será siempre acoplado a un _MD_.
  Desde el punto de vista de _cliente_, los eventos parecen provenir tanto del
  _SD_ como del _MD_. Nunca deben escuchar directamente de _SD_.
> nota: el puntero no guarda relación con el concepto __puntero__ en programación.

#### Almacén de marcos lineales

Recuerdo la teoría de OpenGL cuando manejávamos el almacén único, siempre para
renderizar imágenes en 2D, y el _minúsculo_ cambio necesario para controlar un
doble intercambio.

El proceso es bien sencillo; consiste en _adelantarse_ a lo que el sitstema está
presentando en pantalla. Para esto creamos un _doble almacén_ en el primero, que
subyace en la capa de _entorno_, se realizan los cálculos necesarios para
procesar el mapa de bits, consiste en una entrada de código que es leída igual
que cualquier otro arreglo.

Cuando este primer almacén ha terminado su trabajo, intercambiamos el dispositivo
virtual, para presentarlo en la capa _adyacente_, éste primero, se trata de un
_intercambio_, y el proceso empieza de nuevo.

También es utilizado un tercer almacén, aunque el proceso capaz de controlarlos
de forma eficiente, es bastante mas complejo, ya que con esta técnica hay que
prestar especial atención a la sincronización de tales dispositivos.
