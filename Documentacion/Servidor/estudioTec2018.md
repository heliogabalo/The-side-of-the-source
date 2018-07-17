## Estudio Técnico 2018

[1. preliminares](#i1)
[2. Esquema para el hardware de sistema](i2)
66. Proyeccion de costos
77. Proyección financiera
---

#### <a name="i1">1. preliminares</a> ####



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

#### <a name="i2">2. Esquema para el hardware de sistema.</a> ####



#### Rack para el servidor

- NAS SSD 8 ports(synology 4 ports ejem. DS416) -- encima del armario

home	  1U [xxxx] -- 8 port KVM TRENDnet Switch
office  2U [xxxx] -- Custom Home office VMs (home netmwork)

				2U [xxxx] -- R710s Hyper V cluster node 1 -- con 2 zocalos para CPU
				2U [xxxx] -- R710s Hyper V cluster node 2
home		2U [xxxx] -- R710s Hyper Azure Stack
lab			2U [xxxx] -- R710s Hyper V MGMT 4

				1U [xxxx] -- 700VA Network Equipment
				2U [xxxx] -- 1500VA Synology & Misc.
				2U [xxxx] -- 2200VA R710s

#### distribucion posterior
- switch cisco
- firewall por hardware (pfsense aconsejado)
- router (netgate)
- HP 1810 24 G's -- 2 unidades
- SAI autonomia por dterminar!!!!!!!!
  **complementto instalacion de _una equipo/gasoil_ para el circuito del SAI.
 
 
#### <a name="i66">66. Proyeccion de costos</a> ####


__Hardware del servidor__

1) KVM 8 puertos 

__KVM switch__, conmutador kvm. Se trata de un dispositio físico, que permite al usuario controlar diferentes máquinas o computadoras, desde uno o mas conjuntos de _teclados, monitores y ratones_.

El conmutador KVM, permite al personal de la _central de datos_, conectar a cualquier servidor del _rack_.

[KVM 8port TRENDnet](https://www.trendnet.com/store/products/KVM-Rackmount-Switch/TK-804R)

TRENDnet KVM switch 8port with OSD	----	280.49€

__Alternativas por software__

- Multiplicity
- InputDirector
- Sinergy


__KVM__(hardware), en referencia a _Keyboar, Video, Mouse_, 

__KVM__(software), desambiguacion, _kernel-based virtual machine_. Es una ifraestructura de virtualización para el _núcleo_ de __Linux__, la cuál lo convierte en un _hipervisor_.

2) Custom Home office(home netmwork)

Este es el _módulo del rack_, donde se lleva a cabo la __gestión de red__ del propio servidor.





66.99) Sistema operativo del servidor anfitrión(host/dom0), el _hypervisor_.

Virtualización
Large-scale automation testing

__Linux__

Citrix XenServer 

__Windows__

- HyerV
- Azure



__VMware__

VMware vSphere

77. Proyección financiera

Aquí va todo lo relacionado con el crédio que deba ser solicitado a las entidades
financieras. También incluye el plan de inversión para mejorar el equipo etc.



