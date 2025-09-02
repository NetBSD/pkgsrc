# $NetBSD: Makefile,v 1.20 2025/09/02 06:36:57 wiz Exp $

DISTNAME=		libXfixes-6.0.2
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Xfixes library and extension of X RandR from modular X.org
LICENSE=		mit

CONFLICTS+=		Xfixes-[0-9]*

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xfixes.pc.in

.include "../../devel/meson/build.mk"
X11_LIB_NAME?=		libXfixes
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=		libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
