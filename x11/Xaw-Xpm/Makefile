# $NetBSD: Makefile,v 1.10 1999/05/01 18:23:51 tv Exp $
#

DISTNAME=		Xaw-XPM-1.1
PKGNAME=		Xaw-Xpm-1.1
WRKSRC=			${WRKDIR}/XawXpm
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/X/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.zip.com.au/~bb/XawXpm/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		Xaw3d-*

USE_IMAKE=		yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/Xaw-Xpm
	${MKDIR} ${PREFIX}/share/pixmaps
	${CP} ${WRKSRC}/README-XPM ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/defaults-XawXpm ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
