# $NetBSD: Makefile,v 1.96 2026/01/07 08:49:31 wiz Exp $

DISTNAME=	kactivities-${KF5VER}
PKGNAME=	kactivities5-${KF5VER}
PKGREVISION=	12
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
