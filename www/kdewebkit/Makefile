# $NetBSD: Makefile,v 1.6 2017/02/06 13:54:51 wiz Exp $

DISTNAME=	kdewebkit-${KF5VER}
PKGREVISION=	3
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE Integration for QtWebKit
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
