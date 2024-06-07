# $NetBSD: Makefile,v 1.71 2024/06/07 23:55:50 markd Exp $

DISTNAME=	kwindowsystem-${KF5VER}
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
.  include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
