CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS += -g
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)
GLIB_COMPILE_RESOURCES = $(shell $(PKGCONFIG) --variable=glib_compile_resources gio-2.0)
GLIB_COMPILE_SCHEMAS = $(shell $(PKGCONFIG) --variable=glib_compile_schemas gio-2.0)

SRC = myStyle.c myStyleWin.c myStylePrefs.c main.c
BUILT_SRC = resources.c

OBJS = $(BUILT_SRC:.c=.o) $(SRC:.c=.o)

all: myStyle

org.gtk.Example.gschema.valid: org.gtk.Example.gschema.xml
		$(GLIB_COMPILE_SCHEMAS) --strict --dry-run --schema-file=$< && mkdir -p $(@D)

gschemas.compiled: org.gtk.Example.gschema.valid
	$(GLIB_COMPILE_SCHEMAS) .

resources.c: myStyle.gresources.xml window.ui app-menu.ui
	$(GLIB_COMPILE_RESOURCES) myStyle.gresources.xml --target=$@ --sourcedir=. --generate-source

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

myStyle: $(OBJS) gschemas.compiled
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean:
	rm -f org.gtk.Example.gschema.valid
	rm -f gschema.compiled
	rm -f $(BUILT_SRC)
	rm -f $(OBJS)
	rm -f myStyle
