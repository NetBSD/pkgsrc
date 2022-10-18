# $NetBSD: Makefile,v 1.10 2022/10/18 17:48:47 wiz Exp $

DISTNAME=	xcb-util-cursor-0.1.4
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB port of Xlib's libXcursor
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gm4 gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	cursor/xcb-cursor.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
