# $NetBSD: Makefile,v 1.2 2024/05/29 16:35:03 adam Exp $

DISTNAME=	qqc2-desktop-style-${KF6VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Style for Qt Quick Controls 2 to make it follow your desktop theme
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
