#!/bin/bash

pkg-config --cflags gtk+-3.0
 -pthread -I/usr/include/gtk-3.0 -I/usr/lib64/gtk-3.0/include \
 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pango-1.0 \
 -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include -I/usr/include/pixman-1 \
 -I/usr/include/freetype2 -I/usr/include/libpng12
pkg-config --libs gtk+-3.0
 -pthread -lgtk-3 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangoft2-1.0 -lgdk_pixbuf-2.0 \
 -lpangocairo-1.0 -lcairo -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0 \
 -lgmodule-2.0 -lgthread-2.0 -lrt -lglib-2.0
