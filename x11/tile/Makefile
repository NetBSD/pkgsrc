# $NetBSD: Makefile,v 1.4 2007/01/30 20:39:34 joerg Exp $
#

DISTNAME=		tile_0.7.3
PKGNAME=		tile-0.7.3
PKGREVISION=		1
CATEGORIES=		x11
# cvs only has 0.7.1 and mentions "cvs server loss"...
MASTER_SITES=		http://www.unixdev.net/downloads/tile/0.7.3/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://www.unixdev.net/projects/tile
COMMENT=		X11 Window Tiler

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_DIRS+=		xdg-1.2
GNU_CONFIGURE=		yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
