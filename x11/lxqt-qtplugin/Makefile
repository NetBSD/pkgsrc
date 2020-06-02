# $NetBSD: Makefile,v 1.5 2020/06/02 10:52:03 pin Exp $

DISTNAME=	lxqt-qtplugin-0.15.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE= ${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-qtplugin/
COMMENT=	LXQt platform integration plugin for Qt5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/lxqtplatformtheme.cpp
SUBST_SED.prefix=	-e 's,/usr/local/share,${PREFIX}/share/examples/lxqt/xdg,g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../devel/libdbusmenu-qt5/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
