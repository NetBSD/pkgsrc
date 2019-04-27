# $NetBSD: Makefile,v 1.28 2019/04/27 21:23:20 markd Exp $

DISTNAME=	kwindowsystem-${KF5VER}
PKGREVISION=	1
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

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kwindowsystem.categories \
		${PKG_SYSCONFDIR}/xdg/kwindowsystem.categories

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
