#!/bin/sh

for out in $(netstat -putona | sed 's/|/ /' | awk '{print $5}')
do
  host on $out
done
