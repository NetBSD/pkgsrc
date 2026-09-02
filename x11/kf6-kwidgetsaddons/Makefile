# $NetBSD: Makefile,v 1.16 2026/09/02 19:05:14 wiz Exp $

DISTNAME=	kwidgetsaddons-${KF6VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtWidgets
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PYTHON_BINDINGS=OFF

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
