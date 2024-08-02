# $NetBSD: Makefile,v 1.31 2024/08/02 17:47:30 pin Exp $

DISTNAME=	lxqt-qtplugin-2.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-qtplugin/
COMMENT=	LXQt platform integration plugin for Qt5
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/lxqtplatformtheme.cpp
SUBST_SED.prefix=	-e 's,/usr/local/share,${PREFIX}/share,g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/libdbusmenu-lxqt/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../x11/libfm-qt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
