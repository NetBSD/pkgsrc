# $NetBSD: Makefile,v 1.5 2001/02/17 17:22:40 wiz Exp $
# FreeBSD Id: ports/www/swish-e/Makefile,v 1.3 1999/08/31 02:43:18 peter Exp

DISTNAME=       swish-efiles.1.3.2
PKGNAME=        swish-e-1.3.2
CATEGORIES=     www textproc
MASTER_SITES=   ftp://sunsite.berkeley.edu/pub/swish-e/

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE= 	http://sunsite.berkeley.edu/SWISH-E/
COMMENT= 	Simple web indexing for humans - enhanced

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swish-e ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/user.config ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/test.html ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/swishspider ${PREFIX}/share/examples/swish-e
	${INSTALL_DATA} ${WRKSRC}/README-SWISH-E ${PREFIX}/share/examples/swish-e

.include "../../mk/bsd.pkg.mk"
