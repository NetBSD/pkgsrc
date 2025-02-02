# $NetBSD: Makefile,v 1.47 2025/02/02 09:37:36 wiz Exp $

DISTNAME=	libfm-qt-2.1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libfm-qt/
COMMENT=	Core library of PCManFM-Qt
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

PKG_SYSCONFSUBDIR=	xdg

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/core/fileinfo.cpp
SUBST_FILES.prefix+=	src/core/vfs/vfs-menu.c
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

SUBST_CLASSES+=		unbl3
SUBST_MESSAGE.unbl3=	Undoing buildlink3 paths in cmake exports.
SUBST_STAGE.unbl3=	post-build
SUBST_FILES.unbl3+=	${CMAKE_BUILD_DIR}/src/CMakeFiles/Export/*/fm-qt6-targets.cmake
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR},${PREFIX},g'

TOOL_DEPENDS+=	lxqt-build-tools>=2.1.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/cmake/build.mk"

.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/lxqt-menu-data/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
