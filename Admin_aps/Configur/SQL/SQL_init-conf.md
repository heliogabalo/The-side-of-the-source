#### Configuración inicial

Lo primero es modificar los datos de contraseña, que viene por defecto.
Aprovechamos para echar un primer vistazo a la base de datos y cambiamos
la clave.

Lógicamente primero lanzaremos el servidor local. En sistemas basados en 
Debian esto es como sigue:

    # service start mysql

Aquí nos pide la clave de nuestro usuario _root_ o _Administrador_. 
A continuación conectamos al servidor local:

    # mysql -u root

... y Seleccionamos la base de datos. De momento será utilizada una base de
datos por defecto; la que trae el sistema.
En este punto, ya podemos cambiar la clave de nuestro usuario _Administrador_:

    mysql> update user set password=PASSWORD("mynewpassword") where User='root';
    
Borramos los privilegios almacenados en el _almacen_. Hay que detallar esto.!!
    mysql> flush privileges;

Salimos y reiniciamos servidor para que los cambios sean aplicados.

    mysql> quit
    # service stop mysql
    # service start mysql
  
En El próximo inicio de sesión, nos pedirán los datos de la _nueva contraseña_.

    # mysql -u root -p

#### EXPERIMENTAL
Hay otra _primera_ aproximación a eteos preliminares con la opción:
    
    # mysqld_safe --skip-grant-tables &

Para ver el código de una función o procedimiento se utiliza el comando show:

    mysql> SHOW FUNCTION CODE Nombre_Funcion;

Pero debe haberse compilado `mysql` con la opción `--wit-debug`.


