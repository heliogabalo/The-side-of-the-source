a1-so/rpm-dnf

## rpm
1. [Ver el contenido de un paquete fuente](#i1)
	  1.1 [Desempaquetado](#i1i1)
2. [Establecer el entorno de construccion de __RPM__](#i2)
3. [Construir la fuente](#i3)
4. [Construir la Maqueta](#i4)
5. [Trabajar sobre una fuente __RPM__](#i5)

--- 

#### [1. Ver el contenido de un paquete fuente](i1)

Ver  los metadatos:  
		rpm --query --package --info foo-bar-1.0.src.rpm
> ver notas de manual para mas opciones `--info`.

#### [1.1 Desempaquetado](i1i1)

Desempaquetado de un archivo fuente con __RPM__.

		rpm2cpio foo-bar-1.0.src.rpm |cpio --extract --make-directories --verbose


#### [2. Establecer el entorno de construccion de __RPM__](i2)

- Creamos un directorio de trabajo:
		$ mkdir miDirParaRPM 
		$ cd miDirParaRPM
		$ mkdir {BUILD,RPMS,SOURCES,SPECS,SRPMS}
		
- Editar el `config` de de __RPM__ para decirle donde se encuentran las _cosas_.  
		$HOME/.rpmmacros

... y se añade el siguiente contenido:
		%_topdir		/miDirParaRPM
		%_tmppath		{_topdir}/tmp
		
Configuraciones por defecto y otra _informacón_:
		/usr/lib/rpm/macros

> Deberia comprobarse que el paquete de herramientas para `rpm` esta instaladas
> en el sistema `dnf install rpm-build`


#### [3. Construir la fuente](#i3)


		rpmbuild -ba /miDirParaRPM/SPECS/foo.spec
		
Con esta instruccion se contruye absolutamente todo. Pero. Como es natural, habra
que tener instalados _otros_ paquetes necesarios para el compilado de distintos 
tipos de archivos.

> En un primer intento la opcion `-bp`, me arrojaba un mensaje diciendo que no 
> encontraba el archivo `foo-bar.tar.gz`. Lo que interprete como un _mande...?_.
> Aun no he descifrado el mensaje... pero con la opcion `-ba`, aparace otro 
> mensaje bastante claro: "faltan dependencias", aparece una lista con otras
> aplicaciones que habra que instalar, no listo ninguna por que es algo muy 
> relativo al _equipo/instalacion_.

> __nota:__ para instalar modulos de perl, puede
> hacerse a traves de _cpan_, o tirar de _dnf_ a saco!. Normalmente la distro,
> suele tener empaquetado el archivo en cuestion, ya sea en un `.rpm` o bien
> directamente como paquete del gestor de tu distribucion. Si se busca en 
> _SantGoogle_ como referencia al paquete/distribucion, suele aparacer el 
> nombre que se le dio. Ejem en google: `fedora perl install ExtUtils::Embed` --> 
> `dnf install perl-extutils-embed`




perl(ExtUtils::Embed) es necesario por kernel-4.11.12-100.fc24.x86_64
	perl-devel es necesario por kernel-4.11.12-100.fc24.x86_64
	pesign >= 0.10-4 es necesario por kernel-4.11.12-100.fc24.x86_64




---

## Referencias 
[Using an Source RPM]:[vdt.cs.wisc.edu/internal/native/using-srpm.html]  
[Building a custom ekrnel]:[https://fedoraproject.org/wiki/Building_a_custom_kernel]  
[narrow escape]:[https://www.hiroom2.com/2016/06/25/fedora-24-rebuild-kernel-with-src-rpm]  
[using mock to test packagebuilds]:[https://fedoraproject.org/wiki/Using_Mock_to_test_package_builds]  
[Mock]:[https://github.com/rpm_software_management/mock/wicki]  
