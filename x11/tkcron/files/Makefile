#
# $NetBSD: Makefile,v 1.2 1998/08/07 11:18:18 agc Exp $
#
BINDIR=		${PREFIX}/bin
WISHDIR?=	${BINDIR}

all:		tkcron

tkcron:	
	sed -e "\:/usr/local/bin/wish: s;;${BINDIR}/wish4.1;g" tkcron.tcl > tkcron

install:	all
	install ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} tkcron ${BINDIR}

.include <bsd.own.mk>
