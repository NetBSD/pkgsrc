# $NetBSD: Makefile,v 1.2 2016/12/04 05:17:13 ryoon Exp $

DISTNAME=	kjs-${KF5VER}
PKGREVISION=	1
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Support for JS scripting in applications
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/5.25/portingAids/}

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	perl pkg-config

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
