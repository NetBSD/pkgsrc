# $NetBSD: Makefile,v 1.3 2026/01/07 08:49:12 wiz Exp $

DISTNAME=	knighttime-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	time

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Helpers for scheduling the dark-light cycle
LICENSE=	gnu-lgpl-v2.1 AND mit

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
