# $NetBSD: Makefile,v 1.5 2023/11/12 13:23:46 wiz Exp $

DISTNAME=	berry-0.1.7
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=JLErvin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://berrywm.org/
COMMENT=	Healthy, byte-sized window manager
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CC=${CC}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	X11INC=${X11BASE}/include
MAKE_FLAGS+=	X11LIB=${X11BASE}/lib
MAKE_FLAGS+=	FREETYPEINC=${BUILDLINK_PREFIX.freetype2}/include

# needed for ceil()
LDFLAGS+=	-lm

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
