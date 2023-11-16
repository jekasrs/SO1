# created by Igor Shkurov (igor.shkurov.me@gmail.com)

appname := app

# compilator
C := gcc
# debug info
CFLAGS := -g
# add warnings
CFLAGS += -Wall -Wextra

srcfiles := $(shell find . -maxdepth 1 -name "*.c")
objects  := $(patsubst %.c, %.o, $(srcfiles))

run: all
	./app

all: $(appname)

$(appname): $(objects)
	$(C) $(CFLAGS) -o $(appname) $(objects)

depend: .depend

.depend: $(srcfiles)
	rm -f ./.depend
	$(C) $(CFLAGS) -MM $^>>./.depend;

clean:
	rm -f $(objects)

dist-clean: clean
	rm -f *~ .depend

include .depend
