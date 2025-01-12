# $NetBSD: Makefile,v 1.75 2025/01/12 15:23:28 wiz Exp $

DISTNAME=	kwindowsystem-${KF5VER}
PKGREVISION=	4
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
PLIST_VARS+=	mac x11
.if ${OPSYS} == "Darwin"
PLIST.mac=	yes
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.else
PLIST.x11=	yes

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,${BUILDLINK_DIR}/include,${BUILDLINK_PREFIX.libX11}/include,"
SUBST_FILES.path+=	_KDE_build/CMakeFiles/Export/*/KF5WindowSystemTargets.cmake
SUBST_MESSAGE.path=	Fixing path to libX11 in installed file.
SUBST_STAGE.path=	post-build

.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
