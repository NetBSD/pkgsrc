# $NetBSD: Makefile,v 1.19 2012/10/29 05:07:16 asau Exp $
#

DISTNAME=	xmountains_2.7
PKGNAME=	${DISTNAME:C/_/-/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www2.epcc.ed.ac.uk/~spb/xmountains/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www2.epcc.ed.ac.uk/~spb/xmountains/
COMMENT=	Fractal terrain generator for X11

WRKSRC=		${WRKDIR}
USE_IMAKE=	YES

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
