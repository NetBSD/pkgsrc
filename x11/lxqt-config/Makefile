# $NetBSD: Makefile,v 1.36 2024/05/29 16:35:06 adam Exp $

DISTNAME=	lxqt-config-1.4.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-config/
COMMENT=	System configuration control center
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build

CMAKE_ARG_PATH=	..

# Requires xorg-libinput, which we lack in pkgsrc.
CMAKE_ARGS+=	-DWITH_TOUCHPAD=OFF

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

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

DEPENDS+=	lxqt-menu-data-[0-9]*:../../sysutils/lxqt-menu-data
DEPENDS+=	lxqt-themes-[0-9]*:../../graphics/lxqt-themes
TOOL_DEPENDS+=	lxqt-build-tools>=0.13.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/libkscreen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
