#!/bin/sh

##sphinx-build -b man -c source source/manable1 source/manableOther
##
##Their automatization:
##	for i in  source/man*; do
##		sphinx-build -b man -c source source/manable1 source/manableOther
##	done
		
########## not tested flag here ################
		
for i in  source/man*; do
	sphinx-build -b man -c source $i man/$( basname $i );
done

## it should be on the directory tree

