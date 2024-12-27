# $NetBSD: Makefile,v 1.39 2024/12/27 08:20:47 wiz Exp $

DISTNAME=	obconf-qt-0.16.5
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/obconf-qt/
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${PREFIX}/qt6

TOOL_DEPENDS+=	lxqt-build-tools>=2.1.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
