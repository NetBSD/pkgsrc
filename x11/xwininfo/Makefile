# $NetBSD: Makefile,v 1.19 2026/07/19 17:03:50 wiz Exp $

DISTNAME=		xwininfo-1.1.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Query information about X windows

USE_TOOLS+=		pkg-config

MESON_ARGS+=		-Dxcb-errors=enabled

.include "../../devel/meson/build.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.9
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-errors/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
