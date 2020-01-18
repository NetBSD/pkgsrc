# $NetBSD: Makefile,v 1.2 2020/01/18 21:48:28 jperkin Exp $

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
