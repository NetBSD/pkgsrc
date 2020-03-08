# $NetBSD: Makefile,v 1.4 2020/03/08 16:48:17 wiz Exp $

DISTNAME=	kcalendarcore-${KF5VER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../time/libical/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
