# $NetBSD: Makefile,v 1.21 2005/06/17 03:50:44 jlam Exp $

DISTNAME=	tkinfo-2.8
CATEGORIES=	x11
MASTER_SITES=	http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://math-www.uni-paderborn.de/~axel/tkinfo/
COMMENT=	Tk script to read and display GNU "info" files

DEPENDS=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man1

post-patch:
	cd ${WRKSRC}; \
	  ${MV} tkinfo tkinfo.src; \
	  ${SED} \
	    -e 's|@LOCALBASE@|${LOCALBASE}|g' \
	    -e 's|@X11BASE@|${X11BASE}|g' \
	    < tkinfo.src > tkinfo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkinfo.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
