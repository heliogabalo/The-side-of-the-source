#!/bin/sh
# /mnt/LV/Github/The-side-of-the-source/Respaldo/Local/
# 	--exclude=/path/to/exclude \

cd /mnt/LV/Github
tar -z --create \
	--listed-incremental=/mnt/LV/Github/The-side-of-the-source/Respaldo/Local/incremental.log \
	--file=/tmp/tl$(date +'%d-%m-%H:%M').tar.gz \
	territoriolinux \
