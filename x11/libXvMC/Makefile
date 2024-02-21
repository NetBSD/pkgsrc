# $NetBSD: Makefile,v 1.23 2024/02/21 10:36:20 nia Exp $

DISTNAME=		libXvMC-1.0.14
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		XVideo Motion Compensation Library
LICENSE=		mit

USE_TOOLS+=		pkg-config

USE_CC_FEATURES+=	c99
FORCE_C_STD=		gnu99

PKGCONFIG_OVERRIDE+=		output/meson-private/xvmc.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/xvmc-wrapper.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

X11_LIB_NAME?=		libXvMC
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
