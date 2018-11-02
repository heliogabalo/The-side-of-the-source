#!/bin/sh
HOUSE=/var/src/maintenance/
# 	--exclude=/path/to/exclude \

cd /var/www
tar -z --create \
	--listed-incremental=/var/src/log/local/incremental.log \
	--file=$HOUSE/tl$(date +'%d-%m-%H%M').tar.gz \
	territoriolinux \
