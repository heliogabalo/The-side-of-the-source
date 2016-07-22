#!/bin/sh

path=/media/heliogabalo/Windows/BackingFiles/
name=img1.cow

qemu-img rebase -u -b $path/image_file.raw $path/Unsafe/$name
