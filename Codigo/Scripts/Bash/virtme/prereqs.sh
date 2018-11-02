#!/bin/sh

echo 'Do you want to compile with prereq [yes/no]?'
read req
if $req='yes'
then
	rsync /home/raul/Source-kernel/Prereqs-virtme/prereqs.config /home/raul/Source-kernel/.config
	echo ".config modifitated, now you can build/compile with <virtme>"
	echo "ADVISE:You would want to enable <Kernel .config support> to rescue running <.config>"
	echo "... Guest Method..."
else
	pwd \
	echo "... Regular Method..."
fi
