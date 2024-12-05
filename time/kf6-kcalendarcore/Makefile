# $NetBSD: Makefile,v 1.6 2024/12/05 09:43:26 markd Exp $

DISTNAME=	kcalendarcore-${KF6VER}
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

PKGCONFIG_OVERRIDE+=		_KDE_build/KF6CalendarCore.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../time/libical/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
