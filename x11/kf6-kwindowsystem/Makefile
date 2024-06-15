# $NetBSD: Makefile,v 1.3 2024/06/15 06:22:41 jperkin Exp $

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

.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
