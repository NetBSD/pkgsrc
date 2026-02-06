# $NetBSD: Makefile,v 1.3 2026/02/06 10:06:18 wiz Exp $

DISTNAME=	plasma-activities-stats-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Library for accessing usage data collected by the activities system
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

PKGCONFIG_OVERRIDE+=		_KDE_build/src/PlasmaActivitiesStats.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
