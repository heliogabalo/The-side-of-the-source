## Plantilla 3d.js

En www.threejs.org puede ser encontrado el _mini_.js dentro del apartado github.
En la sección _downloads_ hay tambien un paquete comprimido(bastante grande) en 
formato _.zip_. Habrá que enlazar el _.js_ antes de la etiqueta de cierre `</body>`.


Html:

  <doctype html>
    <html>
      <head>
        <meta charset="utf-8">
        </meta>
      </head>
      <body>
        <div id="container"></div>

        <script src="three.min.js"></script>
        <script src="main.js"></script>
      </body>
    <html>

Css:
  body {
    margin: 0;
  }

  canvas {
    display: block;
  }




Js:

  console.log('hola threejs!')

Esto debe salir en la cónsola de desarrollo(_pequeño test_)pequeño test.
Podemos nombrarlo como queramos, pera asegúrate de enlazar el archivo correcto!.
 
