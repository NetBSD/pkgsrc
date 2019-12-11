# $NetBSD: Makefile,v 1.1 2019/12/11 21:18:06 nia Exp $

DISTNAME=	swc-0.0.0.20191211
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=niacat/}
GITHUB_PROJECT=	swc
GITHUB_TAG=	244dc7d2ff84ba23902db9d70140b25d7a91d56e

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/niacat/swc
COMMENT=	Small Wayland compositor implemented as a library
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config

# Needs access to input, tty, and DRM devices.
SPECIAL_PERMS+=	bin/swc-launch ${SETUID_ROOT_PERMS}

PKGCONFIG_OVERRIDE+=	swc.pc.in

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/wld/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
