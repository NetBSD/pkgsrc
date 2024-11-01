# $NetBSD: Makefile,v 1.54 2024/11/01 12:55:05 wiz Exp $

DISTNAME=	kirigami2-${KF5VER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	QtQuick based components set
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	gmake

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
