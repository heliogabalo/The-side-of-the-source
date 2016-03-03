#!/bin/bash

for i in $( cat emacs_dirs.txt ); do
  rm  -r $i
done
