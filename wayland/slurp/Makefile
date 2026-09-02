# $NetBSD: Makefile,v 1.3 2026/09/02 19:04:51 wiz Exp $

DISTNAME=	slurp-1.5.0
PKGREVISION=	1
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=emersion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/emersion/slurp/
COMMENT=	Tool to select a region in a Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../mk/bsd.pkg.mk"
