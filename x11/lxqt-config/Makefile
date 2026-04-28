# $NetBSD: Makefile,v 1.56 2026/04/28 08:40:28 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-config-2.4.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-config/
COMMENT=	System configuration control center
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

# Requires xorg-libinput, which we lack in pkgsrc.
CMAKE_CONFIGURE_ARGS+=	-DWITH_TOUCHPAD=OFF

.include "../../mk/bsd.prefs.mk"

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/lxqt-config \
		-L${PREFIX}/lib/lxqt-config/

# NetBSD base X11 places xkb config files in a non-standard location
.if ${OPSYS} == "NetBSD" && ${X11_TYPE} != "modular"
XKBSUB=	lib
.else
XKBSUB=	share
.endif

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lxqt-config-input/keyboardlayoutconfig.h
SUBST_VARS.prefix=	X11BASE
SUBST_VARS.prefix+=	XKBSUB

DEPENDS+=	lxqt-themes-[0-9]*:../../graphics/lxqt-themes
TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/cmake/build.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../sysutils/lxqt-menu-data/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/plasma6-libkscreen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
