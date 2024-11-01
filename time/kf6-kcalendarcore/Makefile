# $NetBSD: Makefile,v 1.4 2024/11/01 12:54:44 wiz Exp $

DISTNAME=	kcalendarcore-${KF6VER}
PKGREVISION=	3
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

PKGCONFIG_OVERRIDE+=		_KDE_build/KF6CalendarCore.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../time/libical/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
