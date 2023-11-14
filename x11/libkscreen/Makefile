# $NetBSD: Makefile,v 1.22 2023/11/14 03:53:46 gutteridge Exp $

PLASMAVER=	5.27.9
DISTNAME=	libkscreen-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

TOOL_DEPENDS+=	extra-cmake-modules>=5.102.0:../../devel/extra-cmake-modules

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.102.0
.include "../../devel/kconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.kwayland+=	kwayland>=5.102.0
.include "../../devel/kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
