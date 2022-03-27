# $NetBSD: Makefile,v 1.31 2022/03/27 00:39:57 tnn Exp $

DISTNAME=	kguiaddons-${KF5VER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtGui
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/wayland/platform.mk"

.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
