# $NetBSD: Makefile,v 1.1 2021/02/15 15:05:55 ryoon Exp $

DISTNAME=	xcb-imdkit-1.0.2
CATEGORIES=	x11
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/xcb-imdkit/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/xcb-imdkit
COMMENT=	Implementation of xim protocol in xcb
LICENSE=	gnu-lgpl-v2

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

PKGCONFIG_OVERRIDE+=	src/xcb-imdkit.pc.in

.include "../../devel/uthash/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
