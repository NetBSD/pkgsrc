# $NetBSD: Makefile,v 1.1 2021/12/14 10:34:07 nia Exp $
# The provided CMake file doesn't handle man page installation the
# proper way, and it's simple enough that we might as well rewrite it
# and avoid the CMake dependency entirely.

all: ddate

ddate: ddate.o
	$(CC) $(LDFLAGS) -o ddate ddate.o

ddate.o: ddate.c
	$(CC) $(CFLAGS) -c ddate.c
