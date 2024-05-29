# $NetBSD: Makefile,v 1.68 2024/05/29 16:34:50 adam Exp $

DISTNAME=	kdewebkit-${KF5VER}
PKGREVISION=	2
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE Integration for QtWebKit
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/portingAids/}

USE_TOOLS+=	msgmerge

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
