# $NetBSD: Makefile,v 1.7 2012/07/01 19:05:29 dholland Exp $
#

DISTNAME=		tile_0.7.3
PKGNAME=		tile-0.7.3
PKGREVISION=		2
CATEGORIES=		x11
# cvs only has 0.7.1 and mentions "cvs server loss"...
MASTER_SITES=		http://www.unixdev.net/downloads/tile/0.7.3/

MAINTAINER=		inittab@unixdev.net
HOMEPAGE=		http://www.unixdev.net/projects/tile
COMMENT=		X11 Window Tiler

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
