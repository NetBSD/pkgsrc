# $NetBSD: Makefile,v 1.36 2020/04/12 08:28:12 adam Exp $

DISTNAME=	kwindowsystem-${KF5VER}
PKGREVISION=	3
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

# don't leak buildlink reference in INTERFACE_INCLUDE_DIRECTORIES
# leaked by cmake find_package(X11), better fix welcome.
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-configure
SUBST_MESSAGE.fix-paths=	Cleaning up INTERFACE_INCLUDE_DIRECTORIES
SUBST_FILES.fix-paths=		_KDE_build/CMakeFiles/Export/lib/cmake/KF5WindowSystem/KF5WindowSystemTargets.cmake
SUBST_SED.fix-paths=		-e 's,${BUILDLINK_DIR},${X11BASE},g'

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
