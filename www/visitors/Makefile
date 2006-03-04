# $NetBSD: Makefile,v 1.5 2006/03/04 21:31:04 jlam Exp $
#

DISTNAME=		visitors-0.5
CATEGORIES=		www
MASTER_SITES=		http://www.hping.org/visitors/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hping.org/visitors/
COMMENT=		Very fast web log analyzer

WRKSRC=			${WRKDIR}/visitors_0.5
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/visitors ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/visitors
	${INSTALL_DATA} ${WRKSRC}/*.png ${PREFIX}/share/visitors
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/visitors
	${INSTALL_DATA} ${WRKSRC}/doc.html ${PREFIX}/share/doc/visitors

.include "../../mk/bsd.pkg.mk"
