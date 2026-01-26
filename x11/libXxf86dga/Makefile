# $NetBSD: Makefile,v 1.21 2026/01/26 10:36:07 wiz Exp $

DISTNAME=		libXxf86dga-1.1.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Library for the XFree86-DGA X extension

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xxf86dga.pc.in

.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
