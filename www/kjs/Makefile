# $NetBSD: Makefile,v 1.45 2023/05/22 21:00:08 wiz Exp $

DISTNAME=	kjs-${KF5VER}
PKGREVISION=	6
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for JS scripting in applications
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF5VER:R}/portingAids/}

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	perl pkg-config

.include "../../devel/pcre/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
