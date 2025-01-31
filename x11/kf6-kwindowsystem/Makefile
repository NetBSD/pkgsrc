# $NetBSD: Makefile,v 1.8 2025/01/31 11:52:42 wiz Exp $

DISTNAME=	kwindowsystem-${KF6VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Access to the windowing system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		_KDE_build/KF6WindowSystem.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,${BUILDLINK_DIR}/include,${BUILDLINK_PREFIX.libX11}/include,"
SUBST_SED.path+=	-e "s,-I${BUILDLINK_DIR}/include,-I${BUILDLINK_PREFIX.libX11}/include,"
SUBST_FILES.path+=	_KDE_build/CMakeFiles/Export/*/KF6WindowSystemTargets.cmake
SUBST_FILES.path+=	_KDE_build/KF6WindowSystem.pc
SUBST_MESSAGE.path=	Fixing path to libX11 in installed file.
SUBST_STAGE.path=	post-build

.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
