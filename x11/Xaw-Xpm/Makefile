# $NetBSD: Makefile,v 1.12 2001/02/17 17:06:12 wiz Exp $
#

DISTNAME=		Xaw-XPM-1.1
PKGNAME=		Xaw-Xpm-1.1
WRKSRC=			${WRKDIR}/XawXpm
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/X/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.zip.com.au/~bb/XawXpm/
COMMENT=		Enhanced 3-D widgets based on the Athena Widget set and Xaw3d

CONFLICTS=		Xaw3d-*

USE_IMAKE=		YES
USE_XPM=		YES

post-install:
	${MKDIR} ${PREFIX}/share/doc/Xaw-Xpm
	${MKDIR} ${PREFIX}/share/pixmaps
	${CP} ${WRKSRC}/README-XPM ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/defaults-XawXpm ${PREFIX}/share/doc/Xaw-Xpm
	${CP} ${WRKSRC}/pixmaps/*.xpm ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
