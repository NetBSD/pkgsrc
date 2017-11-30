# $NetBSD: Makefile,v 1.7 2017/11/30 16:45:42 adam Exp $

DISTNAME=	kded-${KF5VER}
PKGREVISION=	6
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extensible deamon for providing system level services
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools
DEPENDS+=	kinit>=${KF5VER}:../../x11/kinit

.include "../../devel/kservice/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
