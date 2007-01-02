# $NetBSD: Makefile,v 1.6 2007/01/02 18:06:50 obache Exp $
#

DISTNAME=		visitors-0.7
CATEGORIES=		www
MASTER_SITES=		http://www.hping.org/visitors/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hping.org/visitors/
COMMENT=		Very fast web log analyzer

WRKSRC=			${WRKDIR}/visitors_0.7
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visitors ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/visitors
	${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/share/visitors
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/visitors
	${INSTALL_DATA} ${WRKSRC}/doc.html ${PREFIX}/share/doc/visitors

.include "../../mk/bsd.pkg.mk"
