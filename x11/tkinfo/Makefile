# $NetBSD: Makefile,v 1.27 2012/10/29 05:06:54 asau Exp $

DISTNAME=	tkinfo-2.8
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://math-www.uni-paderborn.de/~axel/tkinfo/
COMMENT=	Tk script to read and display GNU "info" files

DEPENDS+=	tk>=8.3.2:../../x11/tk

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	cd ${WRKSRC}; \
	  ${MV} tkinfo tkinfo.src; \
	  ${SED} \
	    -e 's|@LOCALBASE@|${LOCALBASE}|g' \
	    -e 's|@X11BASE@|${X11BASE}|g' \
	    < tkinfo.src > tkinfo

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tkinfo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
