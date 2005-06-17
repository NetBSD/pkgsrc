# $NetBSD: Makefile,v 1.3 2005/06/17 03:50:42 jlam Exp $
#

DISTNAME=		visitors-0.4a
CATEGORIES=		www
MASTER_SITES=		http://www.hping.org/visitors/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.hping.org/visitors/
COMMENT=		Very fast web log analyzer

WRKSRC=			${WRKDIR}/visitors_0.4a
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visitors ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/visitors
	${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/share/visitors
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/visitors
	${INSTALL_DATA} ${WRKSRC}/doc.html ${PREFIX}/share/doc/visitors

.include "../../mk/bsd.pkg.mk"
