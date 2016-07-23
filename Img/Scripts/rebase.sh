#!/bin/sh

path=/my/path/to/backing_files/
name=img1.cow

qemu-img rebase -b $path/image_file.raw $path/Overlays/$name
