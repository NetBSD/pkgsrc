# $NetBSD: Makefile,v 1.3 2013/11/12 21:27:45 wiz Exp $

DISTNAME=	xcb-util-cursor-0.1.1
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xcb.freedesktop.org/
COMMENT=	XCB port of Xlib's libXcursor
#LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

#PKGCONFIG_OVERRIDE=	image/xcb-image.pc.in

.include "../../x11/libxcb/buildlink3.mk"
#.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
