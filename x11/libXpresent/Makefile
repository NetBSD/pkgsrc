# $NetBSD: Makefile,v 1.7 2025/09/21 15:28:10 wiz Exp $

DISTNAME=		libXpresent-1.0.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xlib-compatible API for the Present extension

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xpresent.pc.in

X11_LIB_NAME?=		libXpresent

.include "../../devel/meson/build.mk"
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
