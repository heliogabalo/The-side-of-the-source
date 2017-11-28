#!/bin/sh

ps aux|egrep "bash" |awk 'NR==1'|awk '{ print "kill -9", $2}' |sh
