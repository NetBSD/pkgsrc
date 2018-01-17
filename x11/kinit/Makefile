# $NetBSD: Makefile,v 1.15 2018/01/17 20:16:58 markd Exp $

DISTNAME=	kinit-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Process launcher to speed up launching KDE applications
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
