# $NetBSD: Makefile,v 1.18 2000/11/01 14:23:32 tron Exp $
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
	${MKDIR} ${PREFIX}/share/doc/analog ${PREFIX}/lib/analog/lang \
	  ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/lib/analog/images
	${INSTALL_DATA} ${WRKSRC}/lang/* ${PREFIX}/lib/analog/lang
	${INSTALL_PROGRAM} ${WRKSRC}/analog ${PREFIX}/bin
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg \
	  ${PREFIX}/etc/analog.cfg.default
	${TEST} -f ${PREFIX}/etc/analog.cfg || \
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg

.include "../../mk/bsd.pkg.mk"
