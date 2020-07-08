# $NetBSD: Makefile,v 1.1 2020/07/08 14:50:05 nia Exp $

CFLAGS+=	-fPIC -Wall
LDFLAGS+=	-shared -lpsl

all: psl.so

.c.o:
	$(CC) $(CFLAGS) -c $<

psl.so: psl.o
	$(CC) $(LDFLAGS) -o $@ psl.o
