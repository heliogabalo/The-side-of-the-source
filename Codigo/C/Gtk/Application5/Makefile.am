GTK_CFLAGS = 					\
	-I$(top_srcdir)				\
	$(GTK_DEP_CFLAGS)

GTK_LIBS = 					\
        $(top_builddir)/gtk/libgtk-4.la 	\
        $(GTK_DEP_LIBS)


noinst_PROGRAMS = myStyle

exampleapp_CFLAGS = $(GTK_CFLAGS)
exampleapp_LDADD = $(GTK_LIBS)
exampleapp_SOURCES = 				\
	main.c 					\
	myStyle.c myStyle.h 		\
	myStyleWin.c myStyleWin.h 	\
	myStylePrefs.c myStylePrefs.h 	\
	resources.c

BUILT_SOURCES = 				\
	resources.c 				\
	gschemas.compiled

resources.c: Example.gresources.xml $(shell $(GLIB_COMPILE_RESOURCES) --sourcedir=$(srcdir) --generate-dependencies $(srcdir)/Example.gresources.xml)
	$(AM_V_GEN) $(GLIB_COMPILE_RESOURCES) $(srcdir)/Example.gresources.xml \
		--target=$@ --sourcedir=$(srcdir) --generate-source

gsettings_SCHEMAS = 				\
	org.gtk.Example.gschema.xml

@GSETTINGS_RULES@

gschemas.compiled: org.gtk.Example.gschema.xml
	$(GLIB_COMPILE_SCHEMAS) .

EXTRA_DIST = 					\
	window.ui 				\
	app-menu.ui 				\
	prefs.ui 				\
	myStyle.gresources.xml 		\
	org.gtk.Example.gschema.xml

CLEANFILES = 					\
	gschemas.compiled

-include $(top_srcdir)/git.mk
