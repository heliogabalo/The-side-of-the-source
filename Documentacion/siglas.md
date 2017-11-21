## Indice




1. [Referencias Generales](#i1)
	 - 1.1 Referencias SO
2. Referencias a memorias
4. Referencias a Disco Duro
5. [Referincias a Unidades de procesamiento](#i5)
6. [APM(Advanced Power Management)](#i6)
7. Referencias Acpi/Acpica/Tablas-Acpi
9. Referencias a Video
10. Referencias a Supuestos
79. Referencias a criptografia
89. Referencias Cryptomonedas
99. Referencias/enlaces
		- 1. Repositorios			
				 - HTTP
				 - FTP
		- 2. Documentacion
				 - HTTP
				 - FTP		
---
1. [PROCESO DE INSTALACION DE UNA IMAGEN](#i1)
    1. [Crear imagen](#i1)  
    2. [Convertir imagen](#1i2)
## 1. <a name="i1">PROCESO DE INSTALACION DE UNA IMAGEN</a>  
#### Crear imagen

---
## 1. <a name="i1">Referencias Generales</a>

#### OEM  -- Original Equipment Manufacture
#### OS --- Operating system
#### OSL ---  OS Service Layer
#### ABI --
#### SoC -- Sistemas en Chip
#### SCI --- System Control Interrupt
#### HDL -- Hardware Description Language
#### HPET -- High Precision Event Timer
#### APIC --  Advanced Programmable Interrupt Controller
#### LAPIC -- Local component, integrado en el procesador
#### ASIC -- Circuitos Integrados de Aplicación Específica
#### SMI
#### ISA -- Industry Standard Architecture
#### PCI -- Peripheral Component Interconnect
#### PCMCIA -- Personal Computer Memory Card International Association
#### SPI -- Serial Peripheral Interface -- Interfase de periféricos en serie.
#### PIC -- Programmable Interrupt Controller
#### DSP -- Procesadores Digitales de Señal
#### FPGA -- Matrices de puertas reconfigurables
#### BIOS -- Basic Input Output System
#### CMOS -- Complementary metal-oxide-semiconductor (RTC and basic info PC config)
#### SMBIOS -- System Management BIOS, define data structures & acces methods to read BIOS.
#### Northdridge -- Comunicacion directa con CPU y PCI-Express
#### SouthBridge -- Otras operaciones secundarias sobre PCI -- (Serial ATA, SCSI)???
#### ICH -- Input/Output Controller Hub - SouthBridge
#### DPMI -- DOS Protected Mode Interface
#### PCB -- Process Control Block - define el estado actual del sistema operativo.
#### IP -- Intellectual Property(desambiguación).
#### DMI -- Desktop Management Interface.
#### DMI(intel) -- Direct Media Interface(desambiguación)
#### UMI(amd)
#### DVI -- Digital Visual Interface
#### GPGPU -- General Purpous Computing on GPU
#### PE's -- Processing Elements
#### API -- Application Programming Interface
#### CRT -- Tubo de Rayos Catódicos
#### TDP -- Thermal Design Power. Indica la cantidad de W de calor, que puede disipar el sistema antes de alcanzar el máximo d.
#### FMA -- Fused Multiply-Add. Mejora para el cálculo de operaciones con punto flotante.
#### OC -- OverClocking
#### PASID -- Process Adress Space Identifiers, Identificadores del espacio de direccionamiento de proceso.
#### HCI -- Host Controller Interface
#### OHCI -- Open Host Controller Interface to talk to USB 1.1
#### UHCI -- Universal Host Controller Interface
#### EHCI -- Extended? Host Controller Interface
#### AHCI -- ?? Host Controller Interface
#### UDMA -- Ultra Direct Memory Acces
#### EDID -- 
#### JIT -- Just In Time
#### PAE -- Phisical Address Extension
#### FPU -- (Floating Poinmt Unit)??
#### LUN --
#### PMMU -- paged memory management unit
#### AoE -- ATA over Ethernet
#### HID -- Human Interface Device, it take INPUTS and give OUTPUTS.[hardware/hid]:[hid.md]
#### RCU -- Read Copy Update [hardware/procesador]:[rcu.md]
#### PME power management event support
#### UUID -- User Unique Identifier
#### CSR -- Cambridge Silicon Radio
#### IPC -- InterProcess Communication
#### SMP --
---

## 1.1 <a name="i1i1">Referencias SO</a>

#### SysV --  SysV init run level system `/etc/rc.d/` 
#### Systemd -- a system and a service manager
#### Udev -- Dynamic Device management

---
## Referencias Memorias/chips

#### ROM -- Read Only Memory
#### PROM -- Programmable Read Only Memory
#### EPROM --Erasable Programmable Read Only Memory
#### EEPROM -- Electricaly Erasable Programmable Read Only Memory
#### FLASH -- rams de nueva generacion necesita explicar!
#### RAM -- Random Acces Memory
#### MCU -- Memory Controller Unit
#### DRAM -- Dynamic Random Acces Memory
#### DRAM -- RAM dinamica "memoria principal del sistema"
#### SRAM -- RAM estatica (común en el procesador como memoria caché)
#### FPGA -- Field-programmable gate array(integrated circuit)
#### IOMMU -- I/O Memory Management Unit. 
#### DMA -- Direct Memory Acces
#### DDR -- Double Data Rate
#### DDRx -- desambiguación// Data Direction Register
#### GDDR5 -- Double Data Rate type five Synchronous Graphics Random-acces Memory
#### DDR SDRAM -- Double Data Rate Synchronous Dynamic Random-Acces Memory
#### IMC -- Integrated Memory Controller
#### MCH -- Memory Controller Hub
#### MLC -- Multi-Level Cell
#### NAND --
#### NOR
#### VRM -- Voltage Regulator Module
#### PCB -- Printed Circuit Board
#### CFI -- Common flash memory interface
#### ECC memory -- Error-correcting code memory
#### EDAC -- Error Detection And Correction 
#### LDPC
#### SDDC --(Intel) Single Device Data Correction
#### MLC -- Multi-Level Cell
#### SLC -- Single-Level Cell
#### HBC -- Human Based Computation
#### HMC -- Hybrid Memory Cube
#### TSV -- Through-Silicon Vias
#### HBM2 -- High Bandwidth Memory(2ª generacion).
#### MTRR -- Memory Type Range Registers.
#### MRPC -- Memory-maped Remote Procedure Call
#### RSS -- Resident Set Memory Size
#### MSB -- Most Significant Bit?
#### LSB -- Less Significant Bit?
#### SSP -- Synchronous Serial Protocol
#### PSP -- Programable Serial Protocol
#### MOSI -- Master Out Slave In
#### MISO -- Master In Slave Out
#### TXT -- Trusted Execution Technology (intel TXT)
#### ISP -- in-system-programming
#### PDI -- Program and Debug Interface
#### AVR -- family of microcontrollers developed by Atmel.
#### AVR -- Alf and Vegard's Risc (commonly accepted).
#### MIPS -- Millions of Instructions Per Second
#### PXE -- Preboot Execution Enviroment
#### JTAG -- the Join Test Action Group
#### MCU --
#### GPIO -- General Purpose input/output (port/Ver ACPI) 
#### GPIO	   pin genérico en un circuito integrado.
#### POST -- Power-On Self-Test
---

#### <a name="i5">5. Referincias a Unidades de procesamiento</a>

#### NUMA -- Non Uniform Memory Acces (policy to alocate memory areas)[hardware/procesador]:[numa.md]
#### HSA --(AMD) Heterogeneus System Architecture
#### CPU -- Central Process Unit, Unidad de Procesador Central.
#### APU -- Accelerated Processing Unit, is a CPU and a GPU on a single die, known as _Fusion_.
#### MPS -- Multiprocessor Specification
#### MSR -- Model Specific Registers
#### AMD64 -- the x86_64 chipset invented by AMD
#### LMSLE -- (CPU-AMD) Long Mode Segment Limit Enable
#### IA64 -- Intel Itanium chipseet
#### IA32 -- Intel architecture, 32-bit.
#### 8080 -- 
#### LONG MODE -- 64bit OS can acces 64bit instructions
#### REAL MODE -- or _virtual 8086 mode_, apps can't run on LONG MODE
#### UNREAL MODE -- intel 80286, ega video type
#### SMM -- System Management Moode or _rin-2_, all execution is suspended
#### VIA 
#### TRANSMETA
---


#### Referencias Disco Duro

#### IDE -- Integrated Drive Electronic
#### ATA -- AT Attachment
#### ATAPI -- AT Attachment Packet Interface
#### PATA -- Parallel ATA
#### SATA -- Serial ATA
#### MBR -- Master Boot Record
#### VBR -- Volume Boot Record
#### LBA -- Logical Block Addressing
#### CHS -- Cylinder Head Sector
#### GPT
#### EFI
#### UEFI
---


## <a name="i6">Referencias APM(Advanced Power Management)</a>

#### APM -- Advanced Power Management [hardware/apm]:[apm.md]
---

## Referencias Acpi/Acpica/Tablas-Acpi

#### ASWG -- ACPI Specification Working Group
#### API -- Application Programming Interface
#### ACPI -- Advanced Control Power Interface
#### ACPICA --ACPI Component Architecture
#### SLIC -- System Licensed Internal Code
#### OSI -- Operating System Interfaces" (_OSI)
#### OSPM --- Operating System directed Power Management
  ---------------
#### BGRT -- Tabla de recursos del arranque de gráficos.

#### CSRT -- Tabla de recursos del núcleo del sistema.

#### DBG2 -- Tabla 2 del puerto de depuración.

#### DSDT --- Sistema de Descripción de Tabla Diferenciado
#### DMAR -- DMA Remapping table 
#### DRHD -- DMA Remapping Hardware Unit Definition
#### RMRR -- Reserved memory Region Reporting Structure
#### ZLR  -- Zero length reads from PCI devices
#### IOVA -- IO Virtual address.

#### FACP
#### FACS -- Firmware ACPI Control Structure
#### FADT -- Tabla de Descripcion fija ACPI
#### FPDT -- Tabla para la mejora de datos del firmware.

#### GTDT

#### HPET -- Hight Precision Event Timer

#### MADT -- Tabla controlador múltiple de interrupción.
#### MCFG

#### RSDP
#### RSDT

#### SSDT -- System Service Desription Table- Tabla de descripción de servicio de sistema

#### XSDT

#### WSMT
  ---------------
#### DSL  --- .dsl -- extension, disassembled ASL
#### AML -- ACPI Machine Language
#### ASL -- ACPI Source Language
#### ASM --
  ---------------
#### GPE --- General Purpouse Events
#### SCI -- Sistema de control de Interrupcion
---


## Referencias a Supuestos

#### CMMA -- Collaborative Memory Management Assist
#### Intel-VT -- Virtualization technology(by Intel)
#### AMD-V -- Virtualization technology(by AMD side), initialy SVM("Flag", Secure Virtual Machine)


---
## Referencias a Video

#### AGP -- Accelerated Graphics Port
#### APU -- Accelerated Processing Unit, is a CPU and a GPU on a single die, known as _Fusion_.
#### GPU -- Graphic Processing Unit
#### ATI -- GPU vendor acquired by AMD in 2006
#### GART -- Graphics Address Remapping   table
---


## Referencia criptografia

#### GPG -- GnuPG, GNU Privacy Guard
#### SELinux --
#### TLS --
#### bss -- Basis Service Set. on static libs, the need to init vars before call it(c/c++).
#### HMAC -- Hash-Based message authentification code.
---


## Referencias Cryptomonedas

#### ETC -- Ethereum Classic
#### ETH -- Ethereum
#### BlockChain -- Distributed database (equiparable al commit!). Registro público de una
     transaccion de bitcoin.
#### Block -- record in the block chain contining "confirms" and many "waiting transactions"
#### DAO -- Descentralised Autonomous Organisation
#### DAPP -- Decentralized Application
#### Bitcoin -- The concept, the net!
#### bitcoin -- units of account, unidad de medida.
#### bit -- subunidad del bitcoin(BTC, XBT)
#### hash rate -- measuring unit of the processing power of the Bitcoin network.
#### Contract -- an account which contains, and is controlled by EVM code.
#### EVM code -- Ethereum Virtual Machine Code. Programming language 
#### Message -- a sort of "virtual transaction" sent by EVM code
#### Uncle -- The gender-neutral alternative to aunt/uncle
#### Ommer -- a child of a parent, of a parent of a block that is not a parent. Child of an ancestor.
#### Censorship Fault -- a validator failing to accept valid messages from other validators.
#### PoW -- Proof of Work
#### DAG -- Direct Acyclic Graph
---



## Referencias/enlaces

#### 10.1 Repositorios

#### 10.1.1 Nucleo
	- HTTPS
[UML](http://user-mode-linux.sourceforge.net)

	- FTP
[UML-ftp](ftp://ftp.ca.kernel.org/pub/kernel/v2.4/linux-2.4.0-prerelease.tar.bz2)
[Project-builder](ftp://ftp.project-builder.org/)

#### 10.2 Documentacion
	- HTTPS
[IOMMU](http://www.intel.com/content/dam/www/public/us/en/documents/product-specifications/vt-directed-io-spec.pdf)
[RCU](http://www.rdrop.com/users/paulmck/RCU/)
[RCU/Linux-kernel](http://www.rdrop.com/users/paulmck/RCU/linuxusage/rculocktab.html)
[GPMC](http://www.ti.com/lit/pdf/spruh73)
[DDR2 SDRAM](en.wikipedia.org/wiki/DDR2_SDRAM)
[fedoraCustomKernel](https://fedoraproject.org/wiki/Building_a_custom_kernel) muy buena!!!
[Acpi-in-Linux](https://www.kernel.org/doc/ols/2005/ols2005v1-pages-59-76.pdf)
[CodeGuro](https://www.codeguru.com/) buena pero no funciona la busqueda!! SMBIOS Demystified

##### 10.3 Patentes
[RCU-patente](http://liburcu.org/)
