# $NetBSD: Makefile,v 1.1.1.1 2004/01/21 21:04:43 kristerw Exp $
# $FreeBSD: ports/x11/xnodecor/files/Makefile,v 1.1 2003/09/08 07:08:14 edwin Exp $

all:	xnodecor

xnodecor:
	$(CC) -o xnodecor xnodecor.c $(CFLAGS) $(LDFLAGS) $(LIBS) -lX11

install:
	${BSD_INSTALL_PROGRAM} xnodecor ${PREFIX}/bin

clean:
	rm -f *.rej a.out core xnodecor
