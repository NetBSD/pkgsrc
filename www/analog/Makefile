# $NetBSD: Makefile,v 1.17 2000/10/27 03:22:49 tron Exp $
# FreeBSD Id: Makefile,v 1.15 1999/03/15 02:01:27 steve Exp

DISTNAME=       analog-4.13
CATEGORIES=	www
MASTER_SITES=   ${HOMEPAGE} \
		http://www.web42.com/analog/ \
		http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.gekko.de/analog/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://www.analog.cx/

ALL_TARGET=	analog
MAKE_ENV+=	PREFIX=${PREFIX}

do-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/analog
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${PREFIX}/lib/analog/lang
	${INSTALL} -d -o nobody -g nogroup -m 755 \
		${PREFIX}/lib/analog/images
	cd ${WRKSRC}/docs && \
		${INSTALL_DATA} * ${PREFIX}/share/doc/analog
	cd ${WRKSRC}/images && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/images
	cd ${WRKSRC}/lang && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/lang
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analog ${PREFIX}/bin
	cd ${WRKSRC} && \
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg \
	  ${PREFIX}/etc/analog.cfg.default

.include "../../mk/bsd.pkg.mk"
