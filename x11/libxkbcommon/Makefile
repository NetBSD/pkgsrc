# $NetBSD: Makefile,v 1.50 2024/05/29 16:35:06 adam Exp $

DISTNAME=	libxkbcommon-1.7.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://xkbcommon.org/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://xkbcommon.org/
COMMENT=	Library to handle keyboard descriptions
LICENSE=	mit

USE_TOOLS+=	bison pkg-config

MESON_ARGS+=	-Denable-wayland=false

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=		output/meson-private/xkbcommon.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/xkbcommon-x11.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../mk/bsd.prefs.mk"

# native X has a different locale path (lib) than modular X (share)
.if ${X11_TYPE} == native
MESON_ARGS+=	-Dx-locale-root=${X11BASE}/lib/X11/locale
.endif

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
# for tests
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
