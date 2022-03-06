# $NetBSD: Makefile,v 1.1 2022/03/06 08:58:21 nia Exp $

all: chronos.so

.c.o:
	$(CC) $(CFLAGS) -fPIC -c $<

chronos.so: chronos.o
	$(CC) $(LDFLAGS) -shared -o $@ chronos.o
