# Makefile
#

CC = gcc
SH = bash
CFLAGS = -g
LDFLAGS = -lm

PROG = engine

all: $(PROG)

$(PROG): $(PROG).o MazeSolver.o bot.o 

$(PROG).o: $(PROG).c MazeSolver.h

MazeSolver.o: MazeSolver.c MazeSolver.h

bot.o: bot.c


.PHONY: clean lint test

clean:
	rm -rf *.o
	rm -rf tests/*_
	rm -rf $(PROG)

lint:



