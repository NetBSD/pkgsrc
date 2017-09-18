# $NetBSD: Makefile,v 1.13 2017/09/18 09:53:07 maya Exp $

DISTNAME=	kactivities-${KF5VER}
PKGNAME=	kactivities5-${KF5VER}
PKGREVISION=	10
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Core components for the KDE's Activities
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/lib/libKActivities.pc.cmake

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
