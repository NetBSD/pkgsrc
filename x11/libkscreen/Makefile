# $NetBSD: Makefile,v 1.26 2024/05/29 16:35:05 adam Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

TOOL_DEPENDS+=	extra-cmake-modules>=5.102.0:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.102.0
.include "../../devel/kconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.kwayland+=	kwayland>=5.102.0
.include "../../devel/kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
