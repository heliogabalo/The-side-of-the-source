
    $ for f in /etc/ssl/certs/*.pem; do sudo ln -sfn "$f" /etc/ca-certificates/trust-source/blacklist/; done

    $ update-ca-trust

-----

    $ sudo rm DigiCert_* GeoTrust_* Go_Daddy_* GlobalSign_* VeriSign_* StartCom_Certification_Authority* Comodo_* AddTrust_* Thawte_* thawte_Primary_Root_CA* Baltimore_CyberTrust_Root.pem UTN_USERFirst_Hardware_Root_CA.pem Visa_eCommerce_Root.pem

    $ ls /etc/ssl/certs/*.pem | wc -l
    $ 206
    $ ls /etc/ca-certificates/trust-source/blacklist/
    $ 163


Fedora utiliza un sistema de gestion de certificados llamado
`SharedSystemCertificates` para proveer un sistema centralizado de almacén
de certificados.

Parece ser que Firefox en concreto, presta atención al mismo, aunque puede
ser que algunas aplicaciones, no hagan caso de este sistema y, gestionen
los certificados de forma independiente.

Desgraciadamente, como el _software_ puede escojer la manera de gestionar
los certificados, es necesario la adopción de la característica:
`Fedora enforcing` y ser diligente, si queremos que nuestro sistema haga
uso de él.


Procedimiento para aislar certificados _no deseados_:

    $ < /dev/null openssl s_client -showcerts -connect www1.cnnic.cn:https > ccnic
    # mv ccnic /usr/share/pki/ca-trust-source/blacklist/
    # update-ca-trust extract <-- `SharedSystemCertificates`
Riniciar la aplicación, en este caso _Firefox_. 

Después de realizar los pasos, oblengo el siguiente log. Parece que la salida hace referencia
a un módulo de prueba, que hice el otro día. Realmente era de esperar, por que el módulo en
realidad no existe _era una prueba_ para aprender a manejar la carga de módulos sobre 
certificados.

Sin embargo, la autoriada de certificado (CA), sigue presente en el almacén tras haber
reiniciado la aplicación, _Firefox._

p11-kit: invalid config filename, will be ignored in the future: /etc/pkcs11/modules/my-module
p11-kit: couldn't load module: /usr/lib64/pkcs11/my-pkcs11-module.so: /usr/lib64/pkcs11/my-pkcs11-module.so: cannot open shared object file: No such file or directory
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: invalid config filename, will be ignored in the future: /etc/pkcs11/modules/my-module
p11-kit: couldn't load module: /usr/lib64/pkcs11/my-pkcs11-module.so: /usr/lib64/pkcs11/my-pkcs11-module.so: cannot open shared object file: No such file or directory
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: invalid config filename, will be ignored in the future: /etc/pkcs11/modules/my-module
p11-kit: couldn't load module: /usr/lib64/pkcs11/my-pkcs11-module.so: /usr/lib64/pkcs11/my-pkcs11-module.so: cannot open shared object file: No such file or directory
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: invalid config filename, will be ignored in the future: /etc/pkcs11/modules/my-module
p11-kit: couldn't load module: /usr/lib64/pkcs11/my-pkcs11-module.so: /usr/lib64/pkcs11/my-pkcs11-module.so: cannot open shared object file: No such file or directory
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: invalid config filename, will be ignored in the future: /etc/pkcs11/modules/my-module
p11-kit: couldn't load module: /usr/lib64/pkcs11/my-pkcs11-module.so: /usr/lib64/pkcs11/my-pkcs11-module.so: cannot open shared object file: No such file or directory
p11-kit: certdata2pem.py: invalid field line: no colon
p11-kit: certdata2pem.py: invalid field line: no colon

---

fuente: https://ask.fedoraproject.org/en/question/66484/how-to-blacklist-a-specific-ca-certificate/
