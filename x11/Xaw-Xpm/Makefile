# $NetBSD: Makefile,v 1.2 1998/06/05 12:06:12 frueauf Exp $
#

DISTNAME=			Xaw-Xpm-1.1
WRKSRC=				${WRKDIR}/XawXpm
CATEGORIES=			x11
MASTER_SITES=			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=		libs/X

MAINTAINER=			root@garbled.futureone.com

DEPENDS+=			xpm-3.4j:../../graphics/xpm

CONFLICTS=			Xaw3d-1.3

USE_IMAKE=			yes

post-install:
	${LDCONFIG} || ${TRUE}
	${MKDIR} ${PREFIX}/share/doc/Xaw-Xpm
	${MKDIR} ${PREFIX}/share/pixmaps
	${CP} ${WRKSRC}/README-XPM ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/defaults-XawXpm ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
