#!/bin/sh

path=/media/heliogabalo/Windows/BackingFiles/
name=img1.cow

qemu-img rebase -b $path/image_file.raw $path/Overlays/$name
