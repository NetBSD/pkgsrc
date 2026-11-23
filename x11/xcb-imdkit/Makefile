# $NetBSD: Makefile,v 1.6 2026/11/23 20:42:51 nros Exp $

DISTNAME=	xcb-imdkit-1.0.6
CATEGORIES=	x11
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/xcb-imdkit/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/xcb-imdkit
COMMENT=	Implementation of xim protocol in xcb
LICENSE=	gnu-lgpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	src/xcb-imdkit.pc.in

# Illumos needs __EXTENSIONS__ for asprintf
# this also makes strdup visible
CFLAGS.SunOS+=	-D__EXTENSIONS__

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--as-needed

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/uthash/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
