La aplicación para descargar claves públicas no funciona correctamente, o ha sido comprometida. Por lo menos la que yo tengo instalada, tras comprobar la herramienta en una instalación del sistema operativo, en limpio.

gpg2 --locate-keys torvalds@kernel.org gregkh@kernel.org

No hay acción alguna, la cónsola devuelve una nueva línea sin ningún aviso.

Tras efectuar la comprovación correspondiente:

gpg2 --verify linux-4.x.x.tar.sign


Anomalía[cita requerida]

No me fijé en la hora de la descarga, se procede desde el principio.

descarga de archivos día 12-06/18 a las 16:20 Madrid, España
https://www.kernel.org/pub/linux/kernel/v4.x/linux-4.17.1.tar.xz

`$ unxz linux-4.17.1.tar.xz 
$ gpg2 --verify linux-4.17.1.tar.sign 
gpg: assuming signed data in 'linux-4.17.1.tar'
gpg: Signature made Mon 11 Jun 2018 04:43:33 PM EDT using RSA key ID 6092693E
gpg: Can't check signature: No public key
$ gpg2 --locate-keys torvalds@kernel.org gregkh@kernel.org
$ gpg2 --verify linux-4.17.1.tar.sign 
gpg: assuming signed data in 'linux-4.17.1.tar'
gpg: Signature made Mon 11 Jun 2018 04:43:33 PM EDT using RSA key ID 6092693E
gpg: Can't check signature: No public key
$ `

Se procede nuevamente a la descarga y comprovación. Busqueda de la llave pública correspondiente a la firma digital.




