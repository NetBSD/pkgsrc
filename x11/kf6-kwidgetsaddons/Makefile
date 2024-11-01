# $NetBSD: Makefile,v 1.4 2024/11/01 00:54:17 wiz Exp $

#DISTNAME=	kwidgetsaddons-${KF6VER}
DISTNAME=	kwidgetsaddons-6.2.2
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtWidgets
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
