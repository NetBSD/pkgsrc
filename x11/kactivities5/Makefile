# $NetBSD: Makefile,v 1.54 2021/04/21 13:25:32 adam Exp $

DISTNAME=	kactivities-${KF5VER}
PKGNAME=	kactivities5-${KF5VER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Core components for the KDE's Activities
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

PKGCONFIG_OVERRIDE+=	src/lib/libKActivities.pc.cmake

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
