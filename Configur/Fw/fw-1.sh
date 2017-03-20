#!/bin/sh

############################################################
#
# internet <-> router <-> FW <-> Hub <-> LAN
#                         |       o
#                         |     Switch
#                        DMZ
#
#
############################################################

## Ejemplo del manual de Iptables
## Script para firewall entre redes
## Helliogabalo Santos
## www.territoriolinux.net heliogabalo@territoriolinux.net

echo -n Aplicando reglas de FIREWALL...

## FLUSH -- vaciado de reglas existentes...
echo -n Vaciado...

iptables -F
iptables -X
iptables -Z
iptables -t nat -F

## Se establecen políticas por defecto
echo -n Estableciendo políticas por defecto...
iptables -P INPUT DROP
iptables -P OUTPUT DROP
iptables -P FORWARD DROP
iptables -t nat -P PREROUTING ACCEPT
iptables -t nat -P POSTROUTING ACCEPT

## Se empieza a filtrar
## Nota: eth0 es la interfaz conectada al router y eth1 a la LAN(sin efecto en esta red).
## Filtrado hacia la DMZ - Todo lo que viene por el puerto 80 se redirige a la DMZ
iptables -t nat -A PREROUTING -i pte0 -p tcp --dport 80 -j DNAT --to 138.68.78.228:80

## Los accesos de una ip determinada HTTPS se redirigen a esa máquina.
iptables -t nat -A PREROUTING -i pte0 -p tcp --dport 443 -j DNAT --to 138.68.78.228:443

## El localhost se deja(ejem conexiones locales a mysql - WARNING) 
echo -n WARNING -- local host ENABLED !!
/sbin/iptables -A INPUT -i -lo -j ACCEPT

## Al firewall tenemos acceso desde la red local
iptables -A INPUT -s 192.168.1.100-110 -i pte0 -j ACCEPT

## Ahora se hace enmascaramiento de la red local la DMZ para que puedan salir
## También se activa el BIT FORWARDING(Importante!!)
iptables -t nat -A POSTROUTING -S 192.168.1.100-110 -o pte0 -j MASQUERADE
iptables -t nat -A POSTROUTING -S 138.68.78.228 -o pte0 -j MASQUERADE

## Con esto permitimos hacer forward de paquetes en el firewall, es decir
## otras máquinas podrán salir a través del FW.
echo -n ACTIVADO FORWARDING PARA OTRAS MÁQUINAS !!!!
#echo 1 > /proc/sys/net/ipv4/ip_forward
echo -n DESACTIVADO FORWARDING PARA OTRAS MÁQUINAS -- "0" !!!!
cat /proc/sys/net/ipv4/ip_forward

## Permitimos el paso de la DMZ a una BBDD de la LAN
#iptables -A FORWARD -s 138.68.78.228 -d 192.168.1.102 -p tcp --dport 5432 -j ACCEPT
#iptables -A FORWARD -s 192.168.0.102 -d 138.68.78.228 -p tcp --sport 5432 -j ACCEPT

## Permitimos abrir el Terminal server de la DMZ desde/hacia la LAN
#iptables -A FORWARD -s 192.168.1.102 -d 138.68.78.228 -p tcp sport 1024:65535 --dport 3389 -j ACCEPT
#iptables -A FORWARD -s 138.68.78.228 -d 192.168.1.102 -p tcp sport 3389 --dport 1024:65535 -j ACCEPT
iptables -A FORWARD -s 192.168.1.102 -d 138.68.78.228 -p tcp sport 22 --dport 1024:65535 -j ACCEPT
iptables -A FORWARD -s 138.68.78.228 -d 192.168.1.102 -p tcp sport 1024:65535 --dport 22 -j ACCEPT

## Despues cerramos acceso de la DMZ a la LAN
iptables -A FORWARD -s 138.68.78.228 -d 192.168.1.0/24 -j DROP

## Se cierra el acceso de la DMZ al propio firewall
iptables -A INPUT -s 138.68.78.228/24 -i eth2 -j DROP

## Se cierran accesos indeseados al exterior
## nota: 0.0.0.0/0 significa cualquier red.

## Se cierra rango de puertos bien conocidos
iptables -A INPUT -s 0.0.0.0/0 -p tcp -dport 1:1024 -j DROP
iptables -A INPUT -s 0.0.0.0/0 -p udp -dport 1:1024 -j DROP

## Se cierra el puerto de gestión webmin.
iptables -A INPUT -s 0.0.0.0/0 -p tcp -dport 10000 -j DROP

echo " OK. Verifica las reglas aplicadas con: iptables -L -n"
## Fin de script
