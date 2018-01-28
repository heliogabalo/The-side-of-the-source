## Estudio Técnico 2018

1. preliminares
2. Esquema para el hardware de sistema.
66. Proyeccion de costos
77. Proyección financiera
---

1. preliminares

Planificación del local o habitáculo destinado a la instalación del servidor.

Para asegurar que la instalación cumple la normativa vigente, toda la instalación
se lleverá a cabo con cable tipo afumex flexible.

Es conveniente separar el cable (voz/datos) de los circuitos eléctricos
ya que podrían crear interferencias sobre la línea. 

#### Cuadro de control
																														CANTIDAD
- Interruptor magnetotérmico 16A 2 polos -- IC60N 16A. 	--		4
- Interruptor magnetotérmico 20A 2 polos -- IC60N 20A. 	--		2
- Interruptor diferencial 300mA	 2 polos							 	--	 	1

#### Control de temperatura

Línea independiente 16A, para la alimentación del _split_ y la bomba de frío.
- 50 mts cablecillo 2,5mm negro
- 50 mts cablecillo 2,5mm azul
- 50 mts cablecillo 2,5mm verde/amarillo

#### Iluminación

- 50 mts cablecillo 2,5mm negro
- 50 mts cablecillo 2,5mm azul
- 50 mts cablecillo 2,5mm verde/amarillo

#### fuerza
Cuatro líneas independientes 

1 línea para el sistema de alimentación ininterrumpida(SAI)16A.

- 50 mts cablecillo 2,5mm negro
- 50 mts cablecillo 2,5mm azul
- 50 mts cablecillo 2,5mm verde/amarillo

1 línea independientes de 16A.

- 50 mts cablecillo 2,5mm negro
- 50 mts cablecillo 2,5mm azul
- 50 mts cablecillo 2,5mm verde/amarillo

2 lineas independientes de 20A.

- 100 mts cablecillo 2,5mm negro
- 100 mts cablecillo 2,5mm azul
- 100 mts cablecillo 2,5mm verde/amarillo

#### Voz y datos
1 linea independiente fibra(voz/datos)
- 50 mts. cable fibra
- 250 mts. cable CAT6 trenzado
- 5-20 RJ45 hembra
- 5-20 RJ45 macho
- 1 armario distribuidor RACK 60x60?

#### Herramientas

- 1 grimpadora!!
- tester _continuidad_
#### Canalización 

50 mts. tubo reflex(coarrugado reforzado). d25.
1 caja registro 150x100.
2 paquetes bridas 2247-0
3 rollo cinta aislante negro, azul, a/v.

25 mts Tubo cobre(rollo) d
1 tubo pasta soldadura cobre
1 rollo estopa
3-5 angulos 60mm superficie
3-5 mts canal blanca superficie para el split.
3-5 racords tubo cobre

50 mts. tubo reflex CR d16

2. Esquema para el hardware de sistema.

#### Rack para el servidor

- NAS SSD 8 ports(synology 4 ports ejem. DS416) -- encima del armario

home   |1U [xxxx] -- 8 port KVM
office |2U [xxxx] -- Custom Home office VMs 

				2U [xxxx] -- R710s Hyper V cluster node 1 -- con 2 zocalos para CPU
				2U [xxxx] -- R710s Hyper V cluster node 2
home		2U [xxxx] -- R710s Hyper V cluster node 3
lab			2U [xxxx] -- R710s Hyper V cluster node 4
				1U [xxxx] -- 700VA Network Equipment
				2U [xxxx] -- 1500VA Synology & Misc.
				2U [xxxx] -- 2200VA R710s

#### distribucion posterior
- switch cisco
- firewall por hardware (pfsense aconsejado)
- router (netgate)
- HP 1810 24 G's -- 2 unidades
- SAI autonomia por dterminar!!!!!!!!
  **complementto instalacion de _una burra/gasoil_ para el circuito del SAI.
 
66. Proyeccion de costos

Aquí va todo lo relacionado con los gastos del desempeño de la actividad laboral.

77. Proyección financiera

Aquí va todo lo relacionado con el crédio que deba ser solicitado a las entidades
financieras. También incluye el plan de inversión para mejorar el equipo etc.



