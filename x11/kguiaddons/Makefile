# $NetBSD: Makefile,v 1.57 2025/10/23 20:40:02 wiz Exp $

DISTNAME=	kguiaddons-${KF5VER}
PKGREVISION=	6
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtGui
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
.  include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.  include "../../x11/qt5-qtwayland/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_WAYLAND=OFF
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
