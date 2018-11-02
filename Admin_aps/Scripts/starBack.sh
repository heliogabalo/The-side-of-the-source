#!/bin/sh
HOUSE=/mnt/LV/Github/the-side-of-the-source-code/Respaldo/
# 	--exclude=/path/to/exclude \

cd /mnt/LV/Github
tar -z --create \
	--listed-incremental=/mnt/LV/Github/the-side-of-the-source-code/Respaldo/Local/incremental.log \
	--file=$HOUSE/tl$(date +'%d-%m-%H%M').tar.gz \
	territoriolinux \
