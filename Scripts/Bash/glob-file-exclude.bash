##!/bin/bash
#
## shopt -s extglob
## echo images/*
## echo images/!(*.jpg)
## echo images/!(*.jpg|path1|path2)

#### the pattern could be any regex entry, and with that !() we work over 
## a negation match.

## ## with zsh:
## setopt EXTEND_GLOB
## echo images/*
## echo images/*~*.jpg
## So x~y matches pattern x, but excludes pattern y

