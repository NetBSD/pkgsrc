# $NetBSD: Makefile,v 1.14 2006/12/27 13:37:46 joerg Exp $
#

DISTNAME=	xmountains_2.7
PKGNAME=	${DISTNAME:C/_/-/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.epcc.ed.ac.uk/~spb/xmountains/

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://www.epcc.ed.ac.uk/~spb/xmountains/
COMMENT=	Fractal terrain generator for X11

WRKSRC=		${WRKDIR}
USE_IMAKE=	YES

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
