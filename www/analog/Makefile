# $NetBSD: Makefile,v 1.8 1999/09/02 20:16:46 tron Exp $
# FreeBSD Id: Makefile,v 1.15 1999/03/15 02:01:27 steve Exp

DISTNAME=       analog3.32
PKGNAME=        analog-3.32
CATEGORIES=	www
MASTER_SITES=   http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.web42.com/analog/ \
		http://ftp.sunet.se/pub/www/utilities/analog/

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://www.statslab.cam.ac.uk/~sret1/analog/

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

.include <../../mk/bsd.pkg.mk>
