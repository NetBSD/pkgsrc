# $NetBSD: Makefile,v 1.4 2020/01/11 23:58:50 nia Exp $

DISTNAME=	swc-0.0.0.20200111
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}
GITHUB_PROJECT=	swc
GITHUB_TAG=	cd02252db8baf1b80798df78126ea7286779dd23

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/niacat/swc
COMMENT=	Small Wayland compositor implemented as a library
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

# Needs access to input, tty, and DRM devices.
SPECIAL_PERMS+=	bin/swc-launch ${SETUID_ROOT_PERMS}

PKGCONFIG_OVERRIDE+=	swc.pc.in

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.83
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/wld/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
