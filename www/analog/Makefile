# $NetBSD: Makefile,v 1.2 1999/05/09 16:41:15 tron Exp $
# FreeBSD Id: Makefile,v 1.15 1999/03/15 02:01:27 steve Exp

DISTNAME=       analog3.2
PKGNAME=        analog-3.2
CATEGORIES=	www
MASTER_SITES=   http://www.statslab.cam.ac.uk/~sret1/analog/ \
		http://www.web42.com/analog/ \
		http://ftp.sunet.se/pub/www/utilities/analog/
DISTFILES=	${EXTRACT_ONLY} ukdom.tab

MAINTAINER=     tron@netbsd.org
HOMEPAGE=	http://www.statslab.cam.ac.uk/~sret1/analog/

ALL_TARGET=	analog
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAKE_ENV+=	PREFIX=${PREFIX}

do-install:
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/analog
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m 755 \
		${PREFIX}/lib/analog/lang
	${INSTALL} -d -o nobody -g nogroup -m 755 \
		${PREFIX}/www/data/images
	cd ${WRKSRC}/docs && \
		${INSTALL_DATA} * ${PREFIX}/share/doc/analog
	cd ${WRKSRC}/images && \
		${INSTALL_DATA} * ${PREFIX}/www/data/images
	cd ${WRKSRC}/lang && \
		${INSTALL_DATA} * ${PREFIX}/lib/analog/lang
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} analog ${PREFIX}/bin
	cd ${WRKSRC} && \
	${INSTALL_DATA} -m 644 ${_DISTDIR}/ukdom.tab \
	  ${PREFIX}/lib/analog/domains.tab
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg
	${INSTALL_DATA} -m 644 ${WRKSRC}/analog.cfg \
	  ${PREFIX}/etc/analog.cfg.default

.include <../../mk/bsd.pkg.mk>
