#!/bin/sh

echo "type a comment tailing a date "
read comm

if [ comm ]
then
  git add . && git commit -m $comm && git push
else
  echo "Something went wrong!"
fi
