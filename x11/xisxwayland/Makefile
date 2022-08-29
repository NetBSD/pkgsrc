# $NetBSD: Makefile,v 1.1 2022/08/29 12:21:41 wiz Exp $

DISTNAME=		xisxwayland-2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Detect if X server is Xwayland
LICENSE=		mit

USE_TOOLS+=		pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
