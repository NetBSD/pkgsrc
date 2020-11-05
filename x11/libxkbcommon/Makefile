# $NetBSD: Makefile,v 1.27 2020/11/05 09:09:25 ryoon Exp $

DISTNAME=	libxkbcommon-1.0.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://xkbcommon.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://xkbcommon.org/
COMMENT=	Library to handle keyboard descriptions
LICENSE=	mit

USE_TOOLS+=	bison gmake pkg-config

MESON_ARGS+=	-Denable-wayland=false

PKGCONFIG_OVERRIDE+=		output/meson-private/xkbcommon.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/xkbcommon-x11.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "options.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./xkbcommon.map
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./xkbcommon-x11.map
.endif

.include "../../devel/xorg-util-macros/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.10
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
