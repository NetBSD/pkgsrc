# $NetBSD: Makefile,v 1.3 2001/08/29 22:41:27 jlam Exp $
#
# Very simple Makefile used to compile Netscape's ns-remote program
#

PROG	= ns-remote

all:	${PROG}

${PROG}:	remote.c
	${CC} ${CFLAGS} -o ${PROG} remote.c -DSTANDALONE \
	    ${LDFLAGS} -lXmu -lXt -lSM -lICE -lXext -lX11

clean:
	rm ${PROG}
