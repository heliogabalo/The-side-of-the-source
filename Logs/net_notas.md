01/08/16
Llevo un buen rato contectado a internet, mirando páginas, etc, de hecho  
ahora mismo he lanzado un vídeo desde youtube, de hora y media que se esta  
reproduciendo con mi explorador iceweasel.  

Sin embargo las únicas direcciones que parecen mostrar transferencias de datos  
son el getaway: 192.168.0.1, el teléfono de mi madre: 192.168.0.3 y el ordenador   
de mi hermana: 192.168.0.4. La 192.168.0.04, hace referencia a la tarjeta de red  
inhalámbrica de su ordenador portátil. Por qué no sale mi IP?  


  ~~~  
   Currently scanning: 172.18.57.0/16   |   Screen View: Unique Hosts

 144 Captured ARP Req/Rep packets, from 3 hosts.   Total size: 8640
` _____________________________________________________________________________`
   IP            At MAC Address      Count  Len   MAC Vendor
 -----------------------------------------------------------------------------
 192.168.0.1     5c:dc:96:5b:cf:b3    03    180   Unknown vendor
 192.168.0.4     cc:af:78:7d:56:09    124    7440   Unknown vendor
 192.168.0.3     24:1f:a0:a9:7a:73    17    1020   Unknown vendor

  ~~~  
Una nueva direccion IP parece recivir datos de forma extraña:
  ~~~  
   0.0.0.0         cc:af:78:7d:56:09    03    180   Unknown vendor  
  ~~~  
> Según la Wiqi, es una dirección genérica, utilizada para designar  
> una máquina desconocida o inválida, curiosamente tiene la misma  
> MAC que el ordenador de mi hermana  

Añado un tail a kern-log, también de esta mañana:  
  ~~~
Aug  1 10:38:31 NR021AA kernel: [ 3450.572364] hid-generic 0003:046D:C05A.0003: input,hidraw2: USB HID v1.11 Mouse [Logitech USB Optical Mouse] on usb-0000:00:1d.2-2/input0  
Aug  1 10:38:36 NR021AA kernel: [ 3455.800087] usb 3-2: USB disconnect, device number 2  
Aug  1 10:45:46 NR021AA kernel: [ 3885.827690] netdiscover[6607]: segfault at 68 ip b7715d0a sp bfb08684 error 4 in libpthread-2.19.so[b770a000+18000]  
Aug  1 10:52:29 NR021AA kernel: [ 4289.012143] device eth0 left promiscuous mode  
Aug  1 10:52:50 NR021AA kernel: [ 4309.875566] device eth0 entered promiscuous mode  
Aug  1 10:53:24 NR021AA kernel: [ 4344.248142] device eth0 left promiscuous mode  
Aug  1 10:54:32 NR021AA kernel: [ 4411.692062] device eth0 entered promiscuous mode  
Aug  1 11:10:43 NR021AA pulseaudio[1160]: Error opening PCM device front:0: Permiso denegado  
Aug  1 11:33:04 NR021AA pulseaudio[1160]: Error opening PCM device front:0: Permiso denegado  
Aug  1 12:10:33 NR021AA pulseaudio[1160]: Error opening PCM device front:0: Permiso denegado  
  ~~~  
Parece que mi madre es una experta programadora, lol!! y eso sólo utilizando 
el móbil. Que ignorante soy!  

  ~~~  
   Currently scanning: 10.57.59.0/8   |   Screen View: Unique Hosts
  
   1311 Captured ARP Req/Rep packets, from 6 hosts.   Total size: 78660
  ` _____________________________________________________________________________`
     IP            At MAC Address      Count  Len   MAC Vendor
   -----------------------------------------------------------------------------
   192.168.0.1     5c:dc:96:5b:cf:b3    62    3720   Unknown vendor
   192.168.0.4     cc:af:78:7d:56:09    1032    61920   Unknown vendor
   192.168.0.3     24:1f:a0:a9:7a:73    200    12000   Unknown vendor
   0.0.0.0         cc:af:78:7d:56:09    03    180   Unknown vendor
   0.0.0.0         24:1f:a0:a9:7a:73    01    060   Unknown vendor
   10.14.124.199   24:1f:a0:a9:7a:73    13    780   Unknown vendor  
  ~~~  


> Ya no solo maneja el _whasa_ ahora también sabe configurar direcciones IP.

Me gustaría saber como es posible que el livebox muestre actividad, si tanto
mi madre como mi hermana estan viendo la sexta por los nacionales y yo estoy
aquí en mi ordenador.!!.
  ~~~  
 16:15 01/08/16
 779 Captured ARP Req/Rep packets, from 4 hosts.   Total size: 46740
`_____________________________________________________________________________`
   IP            At MAC Address      Count  Len   MAC Vendor
 -----------------------------------------------------------------------------
 192.168.0.1     5c:dc:96:5b:cf:b3    07    420   Unknown vendor
 192.168.0.5     18:28:61:8b:bb:c2    01    060   Unknown vendor
 192.168.0.4     cc:af:78:7d:56:09    416    24960   Unknown vendor
 192.168.0.3     24:1f:a0:a9:7a:73    355    21300   Unknown vendor

  ~~~  


> 192.168.0.5 <- LIVEBOX

Eso me hace reflexionar: Para que narices voy a tirarme dos días programando
reglas para la Nat, la dmz y mi vlan, si aún configurando un filtro de macs
en el DHCP del enrutador, sigo viendo IP's como 10.14.124.199!!
Iptables no funciona!

