#!/bin/sh

echo "type a comment tailing a date "
read comment

if [ comment ]
then
  git add . && git commit -m $comm && git push
else
  echo "Something went wrong!"
fi
