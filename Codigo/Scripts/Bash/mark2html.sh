# find directories
find . -type d | sort | awk '$0 !~ last "/" {print last} {last=$0} END {print last}'


## loop to do something whit they
find /big-directory -type d | sort | awk '$0 !~ last {print last} {last=$0} END {print last}' | while read dir
do
    # Do something useful with $dir
    echo $dir
done

## Busca directorios que contengan archivos MD y, convierte a HTML
#!/bin/bash
for dir in `find /big-directory -type d`
do
  if [ -e $dir/file.md ]; #test if dir contains file
  then
    echo "converting $dir/file.md to HTML..."
    markdown $dir/file.md > $dir/file.html
  fi
done
