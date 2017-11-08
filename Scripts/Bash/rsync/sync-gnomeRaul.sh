#!/bin/sh

 

rsync -arv --exclude=Fw/ \
	--exclude=gtk3 \
	--exclude=Msf \
	--exclude=SQL \
	--exclude=Windows \
	--exclude=xdot_notas.md \
	--exclude=grub \
	~/Github/The-side-of-the-source/Configur/ ~/
	
cp ~/Github/The-side-of-the-source/Configur/gtk3/*.* ~/.config/gtk-3.0/
