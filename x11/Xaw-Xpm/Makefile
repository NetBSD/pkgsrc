# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:32 tsarna Exp $
#

DISTNAME=			Xaw-Xpm-1.1
WRKSRC=				${WRKDIR}/XawXpm
CATEGORIES=			x11
MASTER_SITES=			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=		libs/X

MAINTAINER=			root@garbled.futureone.com
HOMEPAGE=			http://www.zip.com.au/~bb/XawXpm/

DEPENDS+=			xpm-3.4k:../../graphics/xpm

CONFLICTS=			Xaw3d-1.3 Xaw3d-1.5

USE_IMAKE=			yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/Xaw-Xpm
	${MKDIR} ${PREFIX}/share/pixmaps
	${CP} ${WRKSRC}/README-XPM ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/defaults-XawXpm ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
