CC ?= gcc
PKGCONFIG =$(shell which pkg-config)
CFLAGS += -g
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)
GLIB_COMPILE_RESOURCES =$(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)

SRC = miVisor.c miVisorWin.c main.c
BUILT_SRC = resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: miVisor

resources.c: miVisor.gresource.xml window.ui visor-menu.ui
	$(GLIB_COMPILE_RESOURCES) miVisor.gresource.xml --target=$@ --sourcedir=. --generate-source

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

miVisor: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f $(BUILT_SRC)
	rm -f $(OBJS)
	rm -f miVisor
