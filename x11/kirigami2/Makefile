# $NetBSD: Makefile,v 1.2 2018/01/24 19:06:11 markd Exp $

DISTNAME=	kirigami2-${KF5VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	QtQuick based components set
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
