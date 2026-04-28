# $NetBSD: Makefile,v 1.59 2026/04/28 07:59:10 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	libfm-qt-2.4.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libfm-qt/
COMMENT=	Core library of PCManFM-Qt
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_TOOLS+=	pkg-config perl

PKG_SYSCONFSUBDIR=	xdg

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/core/fileinfo.cpp
SUBST_FILES.prefix+=	src/core/vfs/vfs-menu.c
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

# Some of the files in ${BUILDLINK_DIR} are from xsrc, some from
# pkgsrc in the NetBSD X.org native case; these need to be handled
# differently, so we need multiple sed expressions.
#
# This is probably fragile and needs to be checked on updates.
SUBST_CLASSES+=		unbl3
SUBST_MESSAGE.unbl3=	Undoing buildlink3 paths in cmake exports.
SUBST_STAGE.unbl3=	post-build
SUBST_FILES.unbl3+=	${CMAKE_BUILD_DIR}/src/CMakeFiles/Export/*/fm-qt6-targets.cmake
# these are from pkgsrc
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-cursor\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-ewmh\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-icccm\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-image\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-keysyms\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-render-util\),${PREFIX}\1,g'
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb-util\),${PREFIX}\1,g'
# all other libxcb* are from X
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR}\(/lib/libxcb\),${X11BASE}\1,g'
# the rest of the libraries are from pkgsrc again
SUBST_SED.unbl3+=	-e 's,${BUILDLINK_DIR},${PREFIX},g'

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/cmake/build.mk"

.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/lxqt-menu-data/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
