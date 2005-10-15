# $NetBSD: Makefile,v 1.1.1.1 2005/10/15 13:40:49 minskim Exp $
#

DISTNAME=		tile_0.7.3
PKGNAME=		tile-0.7.3
CATEGORIES=		x11
MASTER_SITES=		http://www.unixdev.net/downloads/tile/0.7.3/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://tile.unixdev.net/
COMMENT=		X11 Window Tiler

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_DIRS+=		xdg-1.2
GNU_CONFIGURE=		yes

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
