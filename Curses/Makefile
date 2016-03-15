CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
DEPS= curses_head.h
SOURCES = curses_log.c curses_fselect.c curses_fdraw.c
OBJECTS=$(SOURCES:.c=.o)
LIBS = -lncurses
EXECUTABLE=curses_log


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm *o
