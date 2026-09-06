# $NetBSD: Makefile,v 1.6 2026/09/06 10:23:33 markd Exp $

DISTNAME=	plasma-activities-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Core components for the KDE Activity concept
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
