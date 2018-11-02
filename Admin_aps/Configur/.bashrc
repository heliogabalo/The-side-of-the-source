#!/bin/sh


# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin
HOUSE="/mnt/LV/Github"
export PATH

## Mis preferencias
PS1='$ '

##  Mis alias
alias cl='reset && history -c'
alias github='cd $HOUSE/Github'
alias docs='cd $HOUSE/Github/The-side-of-the-source/Documentacion'
alias sci='cd $HOUSE/GithubThe-side-of-the-source/Scripts'
alias linux='cd $HOUSE/Github/linux-stable'
alias out='> /tmp/log 2&>1'
