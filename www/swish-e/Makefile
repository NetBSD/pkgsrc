# $NetBSD: Makefile,v 1.10 2004/01/20 12:28:00 agc Exp $
# FreeBSD Id: ports/www/swish-e/Makefile,v 1.3 1999/08/31 02:43:18 peter Exp

DISTNAME=       swish-efiles.1.3.2
PKGNAME=        swish-e-1.3.2
CATEGORIES=     www textproc
MASTER_SITES=   ftp://sunsite.berkeley.edu/pub/swish-e/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE= 	http://sunsite.berkeley.edu/SWISH-E/
COMMENT= 	Simple web indexing for humans - enhanced

WRKSRC=		${WRKDIR}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swish-e ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/user.config ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/test.html ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/swishspider ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/README-SWISH-E ${PREFIX}/share/examples/swish-e

.include "../../mk/bsd.pkg.mk"
