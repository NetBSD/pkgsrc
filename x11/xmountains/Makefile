# $NetBSD: Makefile,v 1.16 2007/12/12 20:42:35 wiz Exp $
#

DISTNAME=	xmountains_2.7
PKGNAME=	${DISTNAME:C/_/-/}
PKGREVISION=	1
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
