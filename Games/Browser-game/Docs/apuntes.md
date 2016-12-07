> Hay que empezar a aislar las variables globales y meterlas
> en la función que toca. Hay que estudiar como acceder a ellas,
> desde el ámbito adecuado(scope scope scope).

## Ideas 

### Init() -Function
---
###  Hoisting(elevación)
En javascript una variable puede ser llamada antes de ser
declarada. Lo que ocurre es que Javascript mueve la declaración de
la variable al principio de la página, pero solo la declaración NO LA
INICIALIZACIÓN. 

---
### Ámbito o Scope
En realidad este "esquema" es usado para agrupar el código que contendrá
la aplicación y aislarlo en lo que llamamos encapsulado (_closure_).

    (function() {
    }());

Este _esquema_ también llamado __encapsulado anónimo__, es el procedimiento
habitual para crear un nuevo ámbito en __JavaScript__. Es también usual, ver
otra notación muy similar a la primera, con una _sutil_ diferencia:

    (function() {
    })();

La primera _crea_ la función y después la llama por medio del par `()`, agrupando
toda la _cosa_ en un nuevo grupo de paréntesis.

La última encierra toda la función entre paréntesis`()` y a continuación la
ejecuta, llamádola por medio de otro par de paréntesis `()`.

Claro, aquí nos preguntamos _¿como llamamos a una función que no tiene nombre?_ -es
lógico pensar, que si un documento contiene más de una de estas _bestias-pardas_,
será complicado diferenciar unas de otras! -. Pero cuando el _flujo_ del programa
lee secuencialmente los datos del documento y se encuentra con una de estas __bp__,
hace lo que tenga que hacer, y continua. Dicho de otra forma; la función se llama a
si misma!


Cualquier variable o función inclúida al principio de un documento(script) `.js`
se convierte automáticamente en miembro del _objeto-de-ventana_ en una página. Así
que al incluir _estas_ variables y funciones dentro de otra función o variable
_se crea_ un ámbito al que sólo puede accederse de forma _local_. 

El sentido del encuapsulado en _javascript_; es debido a que no fueron incluidas
de forma nativa las _clases_. A diferencia de otros lenguajes como _C/C++, Ruby, etc._
que sí incorporan esta funcionalidad, en _javascript_ es necesario el uso de esta
técnica, para evitar _interferencias_ con otras variables creadas de forma global.

Existen varias alternativas para evitar esta problemática, aunque todas usan este
mismo concepto de _encapsulado_ para evitar ensuciar el _espacio-de-nombre_ global.

  
#### Exposición de variables.
Una forma de exponer la variable/función dentro de un entorno
precedente es pasarla como argumento en la firma de la función definida.

    (function (someThing) {
      
      var funcionPrivada = function() {
        console.log("Si miras en el cajón de mis calzoncillos +
        '<br />' + igual encuentras algo que no te gusta.")
      }
      
      someThing.each = function(colection, rats) {
        if(Array.isArray(rats)) {
          for(i=0; i<rats.length; i++) {
            iterator(rats[i], i, rats);
          }          
        }
        else {
          for(var key in rats) {
            iterator(rats[key], key, rats);
          }
        }
      };
      
      
    }(someThing));


Una variable Local es creada dentro de la función, cuando ésta inicia y,
eliminada cuando termina.
Cuando asignamos un valor a una variable no declarada, ésta se convierte
automáticamente en una variable GLOBAL.
> apunte a _hoisting(o elevación)_.

---

### jQuery sintax
Hace tiempo hice varios cursos `jQuery` con __CodeSchool__, lo que
recuerdo es que se trata de una herramienta para _manipular el DOM_.
Mediante una serie de técticas propuestas por la librería, manejamos
los elementos de la página de forma _transversal_.

La típica sintaxis de `jQuery`:
  
    $(function() {
    ...
    });

Esta función `$()` será ejecutada tan pronto como cargue la página, o
dicho de otra forma; es _autoejecutada!_.
el _ámbito(scope)_.