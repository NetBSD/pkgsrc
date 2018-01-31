# $NetBSD: Makefile,v 1.1 2018/01/31 19:30:10 markd Exp $

DISTNAME=	qqc2-desktop-style-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Style for Qt Quick Controls 2 to make it follow your desktop theme
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	pkg-config

.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

