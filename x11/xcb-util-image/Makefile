# $NetBSD: Makefile,v 1.6 2022/10/18 22:07:05 wiz Exp $

DISTNAME=	xcb-util-image-0.4.1
CATEGORIES=	x11
MASTER_SITES=	https://xorg.freedesktop.org/archive/individual/lib/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	XCB port of Xlib's XImage and XShmImage
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	image/xcb-image.pc.in

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
