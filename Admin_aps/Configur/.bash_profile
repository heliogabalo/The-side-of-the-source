# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

PATH=$PATH:$HOME/.local/bin:$HOME/bin

export PATH

## Mis preferencias
PS1='$ '

##  Mis alias
alias cl='reset && history -c'
alias github='cd ~/Github'
alias docs='cd ~/Github/The-side-of-the-source/Documentacion'
alias sci='cd ~/GithubThe-side-of-the-source/Scripts'
alias linux='cd ~/Github/linux-stable'
