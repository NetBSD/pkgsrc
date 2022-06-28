# $NetBSD: Makefile,v 1.15 2022/06/28 11:37:00 wiz Exp $

DISTNAME=	obconf-qt-0.16.2
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/obconf-qt/
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${PREFIX}/qt5

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.9:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
