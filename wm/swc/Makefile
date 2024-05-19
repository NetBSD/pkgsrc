# $NetBSD: Makefile,v 1.18 2024/05/19 16:01:26 nia Exp $

DISTNAME=	swc-0.0.0.20230701
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_PROJECT=	swc
GITHUB_TAG=	19893a5ca3239082b904a04fdb9ac7c3a1fb62e2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/swc
COMMENT=	Small Wayland compositor implemented as a library
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

# Needs access to input, tty, and DRM devices.
SPECIAL_PERMS+=	bin/swc-launch ${SETUID_ROOT_PERMS}

# "ld: -r and -pie may not be used together"
MKPIE_SUPPORTED=	no

PKGCONFIG_OVERRIDE+=	swc.pc.in

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.83
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/wld/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
