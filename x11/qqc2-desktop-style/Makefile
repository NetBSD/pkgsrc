# $NetBSD: Makefile,v 1.40 2024/06/07 23:55:50 markd Exp $

#DISTNAME=	qqc2-desktop-style-${KF5VER}
DISTNAME=	qqc2-desktop-style-5.116.1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Style for Qt Quick Controls 2 to make it follow your desktop theme
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
