# $NetBSD: Makefile,v 1.1 2026/04/15 08:45:35 kikadf Exp $

DISTNAME=	wtype-0.4
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=atx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/atx/wtype/
COMMENT=	Xdotool type for Wayland compositors
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
