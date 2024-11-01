# $NetBSD: Makefile,v 1.4 2024/11/01 12:54:44 wiz Exp $

DISTNAME=	kholidays-${KF6VER}
PKGREVISION=	3
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE library for regional holiday information
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
