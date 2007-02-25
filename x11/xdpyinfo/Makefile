# $NetBSD: Makefile,v 1.1.1.1 2007/02/25 05:11:11 dsainty Exp $
#

DISTNAME=	xdpyinfo-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Display information utility for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

# Missing x11/libdmx
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
