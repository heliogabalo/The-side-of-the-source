#!/bin/sh

path=/my/path/to/backing_files/
name=img1.cow

qemu-img rebase -b $path/armery_file.raw $path/Overlays/$name
