# $NetBSD: Makefile,v 1.9 2020/03/08 16:48:18 wiz Exp $

DISTNAME=	swc-0.0.0.20200222
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=michaelforney/}
GITHUB_PROJECT=	swc
GITHUB_TAG=	b5b7214bed4d30ff52afa5e9668c9f4162caf30a

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/michaelforney/swc
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
