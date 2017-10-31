## Indice

- Observaciones
- La peste
- Priorizacion
- En el otro extremo

#### Priorización
Tengo que pensar.

#### Observaciones

Me pregunto cuanto puede costar que una empresa especializada
me envie reportes de quien y cuando ha tenido acceso al repositorio
en red.

Todas las cuestiones legales, en cuanto al uso de software bajo <ampR>
no deberían preocuparme, esa es la forma de demostrar que no estoy
infringiendo el <ampR>.

---
Si yo no he instalado los drivers de CAICOS, puesto que venían en el 
source del núcleo por defecto, y despues de la construcción del nuevo 
nucleo no funcionan. Quiere decir lo siguiente:

- Que se alteró el código del módulo que cargaba el núcleo, ya que el 
firmaware viene en la fuente.
- Que para modificar el nuevo código que carga el nucleo, no basta
con meterlo en un paquete y sobreescribir. Habrá que alterar directamente
la memoria en uso, por lo que el objetivo, será
el initramfs. Van a tratar de mover la imagen de la ram.

Podrían obligar al kernel a cargar un módulo extra, ya que sí, está activa
esa funcionalidad.

Esto último podría degenerar en lo siguiente:

- que se altere uno de los códigos de algun módulo que ya se está 
cargando(narrow scape)!.
- que se fuerce la caga del código en un nuevo módulo(narrow scape)!.

La manera en que van a esconder el código, es puta ciencia ficción, podría
ser cualquier cosa imaginable(a priori, habrá que ver).
De entrada se que en Linux, no va a ser tan fácil hacer saltar por los
aires el directorio temporal. Y que el sistema de ficheros, tampoco les
va a poner las cosas tan fáciles como el Windows.

#### La peste
El punto de entrada del código no deseado, tiene su origen en dos 
posibles vías:

- Acceso exterior, la red.
- La autoejecución de un binario desde una NAND.

Estoy casi convencido de que la puerta se abre desde dentro, y el remoto
inicia el proceso, de sincronizado sobre una o varias VM's.

Por lo que se recomiendan las siguientes medidas:

- Exterior:
1. monitorización de conexión.
2. firewall por hardware y reconfigurado de la topología de red. Un servidor 
pantalla(DMZ) y una NAT donde filtrar.

- Interior:
1. Interruptor físico de desconexión, en todo puerto de entrada. Esto puedo
hacerlo con el soldador.
2. Interruptor por software, desconexión y filtrado de todos aquellos puertos
que no estén siendo utilizados.
3. Sistema de alimentación ininterrumpida. SAI. Para tratar de evitar que journaling no sincronice el disco.
4. Encapsulado de sistema, disco duro HDD(mecánico), para evitar compartir
el MBR. Ya que la tabla ACPI, nativa en Windows, escribe los drivers de 
serie, no estoy seguro, pero creo que esto evitará el intercambio de las
tablas cuando cargue el sistema.

## En el otro extremo

Debo ser cuidadoso por que en el otro extremo hay dos prototipos de 
entidades:

- Benignas
- Malignas
- Conclusión

#### Malignas

Son todas aquellas que van a utilizar todos sus recursos disponibles
para llevar a cabo sus fechorias.

#### Benigno

La peña que insiste en eneñarme cosas en plan, subliminal, y que acaban
hablando de alcachofas, cuando están pensando en capas deshechables. Esto
interfiere con mi naturaleza literal.

#### Conclusión
Esto deshace la esperanza de que el intruso desista de incrustar 
código en abierto, usease utilizando espacio en el disco que yo le
autorize o habilite para que haga sus historias. Sea benigno o maligno
esconderá su mierda en mi código.

- Por lo que hay que encontrar una forma [aguas adentro] de filtrar y excluir.
- Metasploit y sus primos, quedan definitivamente descartados de la 
hoja de ruta. A la espera de encontrar a alguien que colabore en esos temas.
Oferta espacio en disco y conexión VPN. Por configurar.
