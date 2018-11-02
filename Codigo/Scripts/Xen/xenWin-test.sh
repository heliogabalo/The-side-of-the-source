## A starter example!

xen-create-image \
	--dhcp --mac my:my:my:mac:mac:mac \
	--memory 512M --swap 1000M \
	--dist squeeze \
	--mirror http://10.80.16.196/debian \
	--hostname debian.guest.osstest \
	--lvm field-cricket --force \
	--kernel /boot/vmlinuz-2.6.32.57 \
	--initrd /boot/initrd.img-2.6.32.57 \
	--arch i386
