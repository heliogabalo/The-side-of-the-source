* [Contenido](#i11)
* [Introducción](#i1)
* [¿Qúe aspecto tienen los símbolos?](#i2)
* [¿En que se parecen a otros lenguajes?](#i3)
* [¿Como son implementados los símbolos?](#i4)
* [¿Qué son símbolos?](#i5)
* [¿Qué no son los símbolos?](#i6)
* [¿Qué pueden hacer los símbolos por tí?](#i7)
* [¿Cuál es la ventaja o desventaja de los símbolos?](#i8)
* [Sumario](#i9)
* [Referencias y agradecimientos](i99)
***************

# Guía de _symbolos_ Ruby para iniciados #

#### <a name="i11">Contenido</a> ####

     Introducción
    ¿Qúe aspecto tienen los símbolos?
    ¿En que se parecen a otros lenguajes?
    ¿Como son implementados los símbolos?
    ¿Qué son símbolos?
    ¿Qué no son los símbolos?
    ¿Qué pueden hacer los símbolos por tí?
    ¿Cuál es la ventaja o desventaja de los símbolos?
    Sumario


#### <a name="i1">Introducción</a> ####

En su gran mayoría, Ruby se ajusta a la regla de Eric Raymond: La menor sorpresa. Sin  
embargo, el concepto de los símbolos de Ruby precipitó recientemente un animado debate  
entre   29 participantes, 97 post (y contando) en el hilo de la lista de correo ruby-  
talk@ruby-lang.org, con desacuerdos y propuestas diversas. Tal vez, sea requerida,  
algún tipo de documentación :-)  

Estoy escribiendo esta documentación para un público específico: Las personas que  
quieren utilizar Ruby pero no son experimentados usuarios. Tal vez han utilizado Ruby,  
o quizás no, pero no son veteranos en el uso de Ruby.  

Para que ésta determinada audiencia, pueda comprenderlo, la documentación está escrita  
con un mínimo de contenido en el lenguaje, Ruby. En su lugar, este dossier, se basa en  
conceptos generales de programación. Al final, este documento permitirá al principiante  
en   Ruby, utilizar los símbolos correctamente.  Con ésto se pretende que el   código,  
 siempre haga lo que tenga que hacer. Ese es el único objetivo de esta documentación.

Los verdaderos expertos en Ruby, entienden los símbolos de forma intuitiva, por lo que  
no   necesitan esta documentación.  De hecho, un veterano en Ruby podría revisar   el  
documento que está leyendo ahora y, decir que es inexacto. Los conceptos introducidos  
en  este escrito, no coinciden con la implementación real de los símbolos en   Ruby.  

Este documento no pretende explicar la aplicación de los símbolos, si no, explicar cómo  
un programador de aplicaciones, puede pensar en ellos y utilizarlos, para alcanzar los  
resultados deseados. Así como para leer el código de símbolos que contiene.  

Los símbolos pueden ser revisados desde varias perspectivas:  

Algunas de estas ópticas, se explican en este documento, y varias, no son necesarias  
para el uso correcto de los símbolos. Sigue leyendo ...  

#### <a name="i2">¿Qué aspecto tienen los símbolos?</a> ####

Ésta es un área, donde todo el mundo coincide. La mayoría de símbolos se parecen a dos  
puntos, seguidos por una cadena sin comillas:  

		:mi_nombre

Otra   forma de escribir un símbolo,   es con dos puntos seguidos de la cadena   entre-  
comillada, que es como el símoblo, representa a la cadena con espacios:  

		:'Esteban estuvo aquí, pero se ha marchado'

Lo anterior es un símbolo. Su representación es:

		"esteban estuvo aquí, pero se ha marchado"

		#!/usr/bin/env ruby
		puts :'I love Ruby.'
		Puts :'I love Ruby.'.to_i

		usuario@root $

		usuario@root $ ./test.rb
		I love Ruby.
		10263
		usuario@root $

Con   los símbolos, pueden utilizarse  tanto  comillas simples como dobles, siempre   y  
cuando sean del mismo tipo, al empezar o terminar la frase. Simples o dobles, la cadena  
y la representación numérica es idéntica y el objecto_Id es el mismo.  

Los   símbolos son inmutables.  Su valor se mantiene durante todo el programa.   Nunca  
aparecen en el lado izquierdo de una asignación. Jamás verá esto:  

		:mi_nombre = "esteban"

Si lo intenta, obtendrá el siguiente mensaje de error:  

		usuario@root $ ./test.rb
		./test.rb:37: parse error, unexpected '=', expecting $
		:mi_nombre = "esteban"
		usuario@root $

Los símbolos son usados de esta forma:  

		mi_cadena = :estebanT

ó :  

		mi_cadena = :estebanT.to_s

ó  


		mi_int = :esteveT.to_i

ó  

		attr_lector = :estebanT

Ahora ya sabe de que estamos hablando. Naturalmente, tendrás un montón de preguntas.  
Sigue leyendo ...  

#### <a name="i3">¿En que se parecen a otros lenguajes?</a> ####

No estoy cualificado para responder esto. De cualquier forma, no importa. Tratar  
de responder a esta pregunta cuando se empieza a estudiar Ruby, puede liarlo todo,  
aún más.  


#### <a name="i4">¿Como son implementados los símbolos?</a> ####

Para responder a esta pregunta, hay que leer el código C, con el que Ruby (en realidad  
el ejecutable) fue construido. Sin embargo, si usted es nuevo en Ruby, o utiliza Ruby  
por que le gusta y, no es usted una autoridad en Ruby. Es esta una pregunta, que no  
necesita contestar en este momento.  

Por ahora, es mejor ignorar todas las discusiones sobre como implementar los símbolos  
en Ruby.  


#### <a name="i5">¿Qué son símbolos?</a> ####

Es una cadena. No es un objeto. No es un nombre.  

Hay  elementos de verdad en cada una  de las afirmaciones anteriores y, sin   embargo,  
en  mi opinión, no son valiosos. En parte porque dependen de un profundo  conocimiento  
de  Ruby, el comprender su significado. Yo prefiero responder a la pregunta   "Qué son  
símbolos", de una manera independiente al propio lenguaje.  

Símbolo en Rubi, es un concepto que representa tanto a números (entero) como a cadenas  
(string).  


En la práctica, el símbolo de Ruby, no contiene cadenas o números -la própia cadena y  
el número, son guardados en otro lugar. Esto no es importante para la comprensión de  
cómo funciona. Así que siéntase libre de pensar en el símbolo de Ruby, como un reci-  
piente   capaz de contener ambos, cadena y número. De esta forma resulta más   fácil  
comprender el concepto.  


Puede derivar en su código, la representación de un número. Con la sintaxis :  

		:mi_simbolo.to_i

y la representación de una cadena con:  

		:mi_simbolo.to_s

En la mayoría de situaciones, un símbolo consigue la representación de una cadena,  
incluso sin la conversión  

		.to_s

La representación de una cadena de números, es MUCHO mas importante que la parte  
numérica. Esta parte numérica, es rara vez utilizada.  

Vamos a explorar aún más, el uso de código:  

		#!/usr/bin/env ruby

		puts :esteban
		puts :esteban.to_s
		puts :esteban.to_i
		puts :esteban.class


El código anterior, imprime por pantalla cuatro líneas. La primera línea imprime la  
representación de la cadena, porque así está configurado el método puts(). La segunda  
línea es una conversión explícita de la cadena. La tercera una conversión explícita de  
un entero. La cuarta imprime el tipo de símbolo.  

El resultado del código anterior, es el siguiente:  

		[usuario@root usuario]$ ./test.rb 
		stevan
		steban
		10257
		Symbol
		[usuario@root usuario]$

La   primera línea, muestra la  representación de la cadena. Tenga en cuenta que   la  
representación de la cadena es  idéntica a los dos puntos, seguidos por la cadena. La  
segunda línea, primero convierte el símbolo a una cadena, luego lo imprime. La salida  
por pantalla es la misma, pero la conversión explícita al objeto cadena, ofrece algunas  
capacidades   adicionales, que podrá, o no, necesitar después. Mas adelante se   habla  
sobre ello, en este mismo documento.  

La tercera línea, muestra la representación entera del símbolo. Es un número sin una  
utilidad significativa y, apenas puede cambiarse. La cuarta línea muestra que es un  
objeto de la clase Symbolo.  

Ahora vamos a explorar un código, que demuestra que el valor de un símbolo, no puede  
cambiarse en tiempo de ejecución.  

		#!/usr/bin/env ruby
		:steban = "Gran Esteban"

		[usuario@root usuario]$ ./test.rb
		./test.rb:2: parse error, unexpected '=', expecting $
		:steban = "Gran Esteban"
				    ^
		[usuario@root usuario]$


Vaya,   hemos fallado miserablemente.   Tal vez si cambiamos la representación de   la  
cadena:  

		#!/usr/bin/env ruby
		:esteban.to_s = "Gran Esteban"


		[usuario@root usuario]$ ./test.rb
		./test.rb:2: undefined method `to_s=' for :steve:Symbol (NoMethodError)
		[usuario@root usuario]$


#### <a name="i55">¿Qué pasa con el número entero?</a> ####

		[usuario@root usuario]$ ./test.rb
		./test.rb:2: undefined method `to_i=' for :steve:Symbol (NoMethodError)
		[slitt@mydesk slitt]$

		[usuario@root usuario]$ ./test.rb
		./test.rb:2: undefined method `to_i=' for :steve:Symbol (NoMethodError)
		[usuario@root usuario]$


El entero no puede ser el brazo armado. Por supuesto, to_i y to_a, nunca estuvieron  
destinados   a ser métodos,  (en realidad son las conversiones, pero esto no   debe  
considerarse ahora mismo). Es bastante obvio que un símbolo no puede cambiarse  en  
tiempo de ejecución. En informática decimos que es inmutable.  

Un último punto. En un programa, cada aparición de un símbolo con el mismo nombre, en  
realidad es el mismo objeto. Esto no es cierto para las cadenas(strings).  

		[#!/usr/bin/env ruby

		puts :mivalor.object_id
		puts :mivalor.object_id
		puts "mivalor".object_id
		puts "mivalor".object_id

		[usuario@root usuario]$ ./test.rb
		2625806
		2625806
		537872172
		537872152
		[usuario@root usuario]$


Como puede verse, en ambos casos,  :mivalor  tiene el mismo objeto_ID. En cambio   con  
"mivalor" se han producido dos objeto_Id distintos. En los primeros dos casos, se hacia  
referencia al símbolo, por lo que nos ha devuelto el mismo objeto_ID. Así es como   se  
 ahorra memoria con el uso de símbolos.  

Basándonos en lo que se ha presentado hasta ahora en esta sección, puede añadirse una  
respuesta indendiente a la pregunta "qué es un símbolo".  

*     Un símbolo de Ruby es algo que contiene un valor numérico (entero) y la  
representación de una cadena.  
* La representación de la cadena es mucho más importante y también usada más a menudo.  
* El valor del símbolo de Ruby es la parte del nombre del propio símbolo, menos los dos  
puntos que le preceden.
* Un símbolo en Ruby, no puede ser cambiado en tiempo de ejecución.  
* Múltiples usos del mismo símbolo, asumen identico ID_objeto y son el mismo objeto.  

Ahora vamos a introducir algo de la terminología específica de Ruby. Prácticamente  
cualquier cosa en Ruby, es un objeto, los símbolos no son una excepción. Son objetos.  


#### <a name="i6">¿Qué no son los símbolos?</a> ####

Un   símbolo en Ruby no es una cadena. Las objetos de cadenas en Ruby, tienen   métodos  
como capitalize o center. Los símbolos es Ruby no tienen estos métodos.  

		#!/usr/bin/env ruby
		micadena = :esteban.capitalize
		puts micadena

		[usuario@root usuario]$ ./test.rb
		./test.rb:2: undefined method `capitalize' for :esteban:Symbol (NoMethodError)
		[usuario@root usuario]$


Como anotación al margen, si se pretende capitalizar, la representación de una cadena,  
primero será necesario convertirla a una cadena:  

		#!/usr/bin/env ruby
		micadena = :esteban.to_s.capitalize
		puts micadena

		[usuario@root usuario]$ ./test.rb
		Steban
		[usuario@root usuario]$


Un símbolo no es sólo un nombre. Lo siguiente ilustra el uso de un símbolo como  
un nombre:

		attr_reader :length

Aquí se está nombrando tanto al método length() como a la variable de instancia 
`@length`.

Sin embargo, los símbolos pueden ser usados para contener culaquier tipo de cadena  
inmutable. Puede usarse como una constante, pero probablemente, tendría que utilizarse  
un identificador que comenzase con una letra mayúscula.  

La cuestión es que los símbolos no están restringidos a ser usados sólo con nombres.  

Decimos  a  menudo que los símbolos son  usados como nombres, pero equipararlos a  un  
nombre  no es una definición exacta. En cambio, decir que los símbolos, son usados para  
contener nombres, si es una afirmación razonablemente correcta.  

Un símbolo es un objeto, pero ¿y qué?  

Sin lugar a dudas, un símbolo es un objeto. Casi todo en Ruby es un objeto, por lo que  
decir que un símbolo es un objeto, en realidad no explica nada significativo.  


#### <a name="i7">¿Qué pueden hacer los símbolos por tí?</a> ####

Un símbolo es una forma de pasar información de la cadena, asumiendo siempre que:  

* La cadena no puede ser alterada en tiempo de ejecución.
* La cadena no necesita métodos de la clase String.

Puesto que un símbolo, puede ser convertido en una cadena con el método .to_s  puede  
crearse   una cadena, con el mismo  valor que la representación de la cadena  de  un  
símbolo.  
Puede entonces, cambiarse esa cadena, para aprovechar los métodos de la clase String.  

Un gran número de aplicaciones de símbolos podrían ser manejadas por cadenas.  
Por ejemplo:  

		attr_writer :length

Incluso adelantarnos con:  

		attr_writer "length"

Ambos procedimientos, crean un método constructor llamado length. A su vez, crea una  
variable  de instancia  llamada @length. Si esto parece magia, piensa que  el   truco  
mágico,   está hecho por `attr_writer`,  no por el símbolo. El símbolo   (o la   cadena  
equivalente) sólo funciona como cadena para decir a `attr_writer` como nombrar al método  
que ha creado, y como nombrar a la variable de instancia, que ha creado el método.  

Para ver de manera simplificada, la "magia" de `attr_writer`, observe el siguiente  
programa:  


		#!/usr/bin/env ruby

		def haz_me_un_constructor(elnombre)
		 `eval <<-SETTERDONE`
		 def #{elnombre}(miarg)
			@#{elnombre} = miarg
		 end
		 SETTERDONE
		end

		class Ejemplo
		 haz_me_un_constructor :simbolo
		 haz_me_un_constructor "cadenaG"

		 def mostrar_simbolo
			puts @simbolo
		 end

		 def mostrar_cadenaG
			puts @cadenaG
		 end
		end

		ejemplo = Ejemplo.new
		ejemplo.simbolo("ES UN  SIMBOLO")
		ejemplo.cadenaG("ES UNA CADENA")
		ejemplo.mostrar_simbolo
		ejemplo.mostrar_cadenaG



La función anterior, `haz_me_un_constructor`, es una función muy simplificada de  
`attr_writer`. No implementa el signo igual, por lo que al utilizar el constructor,  
debe señalar el argumento entre paréntesis, en lugar de un signo igual. No se hacen  
iteraciones, sobre múltiples argumentos, por lo que el constructor, únicamente toma un  
argumento. Después toma los argumentos individualmente con  `:simbolo`  y  "cadenaG".  

Con el constructor hecho, el programador de la aplicación, puede acceder al constructor por medio de  ejemplo.simbolo("ES UN SIMBOLO").

A continuación se muestra la salida por pantalla:

		[usuario@root usuario]$ ./test.rb
		ES UN SIMBOLO
		ES UNA CADENA
		[usuario@root usuario]$

En muchas situaciones, puede usarse una cadena en lugar de un símbolo. Tal vez, con el  
uso   de una cadena, el rendimiento disminuiría. Si una cadena literal,   es utilizada  
reiteradamente, sin duda, consumirá más memoria que su símbolo análogo. Quizás el uso  
de la cadena, sería menos legible, o menos habitual. Por lo general, puede usarse una  
cadena, donde usaríamos un símbolo. Con una excepción ...

Si es necesario usar una "cadena" (término utilizado libremente), que no deba ser  
alterada, entonces hay que utilizar el símbolo, ya que el valor de un símbolo, no puede  
se modificado en tiempo de ejecución.  

#### <a name="i8">¿Cuál es la ventaja o desventaja de los símbolos?</a> ####

Generalmente los símbolos aportan ventajas de rendimiento. Cada programador identifica  
al símbolo con un nombre (por ejemplo MiSimbolo), pero el programa, puede identificarlo  
por su representación numérica, que por supuesto, es una búsqueda más rápida.  

Cuando dos cadenas son comparadas, en algún lugar, algunos punteros de la capa de  
abstracción, debe señalar ambas cadenas. Cuando dos símbolos de Rubi son comparados y,  
su representación numérica es igual, entonces los símbolos son iguales.  

Si  `:misimbolo`  va  a  ser  utilizado veinte veces en el programa,  cada  uso  de  
`:misimbolo` se referirá al mismo objeto exactamente. La misma representación numérica y  
la misma representación de la cadena. Esto puede mejorar el rendimiento. Por que cada  
`:misimbolo`  hace referencia a un único objeto y, está "definido" (uso el término  
vagamente) por una cadela literal que consume memoria.  

Por otro lado, una vez que el símbolo es definido, su uso reiterado, no consume memoria  
adicional. Así que si usted usa la misma cadena literal, decenas o centenares de veces,  
sustitúyala por símbolos. Los hash (o estructura básica de datos) son un claro ejemplo.  

Símbolos   no pueden  ser cambiados en  tiempo de  ejecución, esta  regla que   viene  
repitiéndose a  lo largo  de éste artículo, además de ser verdad, es una ventaja.   Si  
usted necesita que algo permanezca invariable (una constante), y no pretende utilizar  
un identificador con la primera letra en mayúscula, entonces el símbolo es la solución.  

La  gran  ventaja de los símbolos es  que son inmutables( no pueden ser alterados   en  
tiempo de ejecución), y algunas veces, es precisamente esto lo que se pretende.  

Otras veces, es lo contrario. Por lo general, el uso de cadenas implica manipulación,  
algo que no puede hacerse -al menos directamente, con el uso de símbolos.  

Debe considerarse otra desventaja, y es que los símbolos, no disponen del conjunto de  
métodos de instancia, propios de la clase String. Estos últimos métodos, hacen la vida  
del programador mucho más fácil.  


#### <a name="i9">Sumario</a> ####

Símbolos de Ruby, generaron un hilo, en la lista de correo ruby-talk@ruby-lang, con 97  
posts. Hubo muchos desacuerdos, algunos de los cuales, alcanzaron altas temperaturas.  

Veinte personas, la mayoría más inteligentes que yo, tenían opiniones distintas, sobre  
como explicar los símbolos. Así que si alguien le dice, que su método para explicar los  
símbolos, es el más correcto, será probablemente el  más incorrecto de todos.  

Como   entienda  usted los símbolos,  no importa. Los veteranos de Ruby,  sabrán   como  
usarlos con mayor eficacia, para obtener el mejor de los resultados. El problema es que  
los iniciados en el lenguaje, Ruby, no saben como utilizarlos para conseguir los resul-  
tados deseados, así que deben escuchar y, tratar de aprender de los más veteranos.  

Programadores   mas experimentados, basan sus explicaciones -en ocasiones   contradic-  
torias, en costumbres específicas, preferencias o incluso implementaciones  internas,  
que provocan mayor confusión, entre los neófitos de Ruby.  

Este documento está dirigido expresamente a los profesos, en el lenguaje. Es usada, una  
pequeña, implementación específica de los símbolos.  

Algunos detalles no son comentados, pero en su lugar, aporta valiosa información para  
el  iniciado.  Necesaria para lograr una correcta implementación de los símbolos,   así  
como su lectura y comprensión.  

Las siguientes afirmaciones, son muy útiles en el uso (o no uso) de los símbolos:  

* Un símbolo en Ruby, se escribe con dos puntos, seguido por carácteres (:misímbolo).
* Un símbolo en Ruby es algo que tiente tanto un número(entero) como una cadena.
* El valor de una cadena de símbolos en Ruby, es el nombre del símbolo, el doble punto  
`( : )`.
* Un símbolo de Ruby, no puede ser alterado en tiempo de ejecución.
* Tanto la representación de la propia cadena, como la representación de la  
parte numérica(entera), no puede modificarse en tiempo de ejecución.  
* Los símbolos de Ruby, son útiles en la prevención de modificaciones.
* Como la mayoría de cosas en Ruby, un símbolo es un objeto.
* Cuando un programa es diseñado, normalmente puede utilizarse una cadena en  
lugar de un símbolo. Excepto si debe prevenirse la modificación de la cadena.  
* Objetos de símbolos, no tienen el rico conjunto de métodos de instancia,  
que si tiene la clase String.  
* Tras el primer uso de  :misimbolo  el resto de referencias al símbolo  
`:misimbolo` no es consumida memoria adicional. Todos son el mismo objeto.  
* Símbolos de Ruby, ahorran memoria, sobre un gran número de idénticas  
cadenas literales.  
* Símbolos de Ruby, mejoran la velocidad de ejecución de un programa, en al  
menos un grado.  


#### <a name="i99">Referencias y agradecimientos</a> ####

__Fuente__: Troubleshooters.Com *  Code Corner * Linux Library  

Troubleshooters.Com, Code Corner and Ruby Revival Present  
The Ruby_Newbie Guide to Symbols  
Copyright (C) 2005 by Steve Litt  
Nota: Todos los materiales en Ruby Revival, son proporcionados tal y como están escritos. La lectura de tales materiales relativos a Ruby Revival, asume la aceptación de los mismos.  Los riesgos derivados del uso de éstos materiales, está implícito en la aceptación de la licencia, absolviendo de cualquier responsabilidad,  a los autores, propietarios y a cualquiera que haya estado involucrado en el proyecto Ruby Revival, incluidos errores y/u omisiones en los materiales. Si las condiciones no son aceptadas por terceros, no debe continuarse leyendo esta documentación.

Al 99'9% de los lectores que son responsables de sus acciones: Pido disculpas sinceramente, pero es necesario implicar a los lectores con el aviso, mencionado.




<ul id="firma">
	<li><b>Traducción:</b> Heliogabalo S.J.</li>
	<li><em>www.territoriolinux.net</em></li>
</ul>


