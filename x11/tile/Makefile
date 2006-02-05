# $NetBSD: Makefile,v 1.2 2006/02/05 23:11:43 joerg Exp $
#

DISTNAME=		tile_0.7.3
PKGNAME=		tile-0.7.3
PKGREVISION=		1
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
