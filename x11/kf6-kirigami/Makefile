# $NetBSD: Makefile,v 1.11 2026/01/07 08:49:32 wiz Exp $

DISTNAME=	kirigami-${KF6VER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	QtQuick based components set
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	gmake pkg-config

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
