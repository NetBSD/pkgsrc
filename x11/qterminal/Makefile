# $NetBSD: Makefile,v 1.4 2020/04/12 08:29:20 adam Exp $

DISTNAME=	qterminal-0.14.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/qterminal/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://lxqt.org/
COMMENT=	Terminal emulator for Qt5
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${PREFIX}/qt5

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qtermwidget/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
