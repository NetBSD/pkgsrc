# $NetBSD: Makefile,v 1.28 2024/06/07 23:55:47 markd Exp $

DISTNAME=	kcalendarcore-${KF5VER}
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../time/libical/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
