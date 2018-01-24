# $NetBSD: Makefile,v 1.16 2018/01/24 19:06:11 markd Exp $

DISTNAME=	kdesignerplugin-${KF5VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Integration of Frameworks widgets in Qt Designer/Creator
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/kplotting/buildlink3.mk"
.include "../../www/kdewebkit/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
