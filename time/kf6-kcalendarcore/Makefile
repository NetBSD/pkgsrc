# $NetBSD: Makefile,v 1.15 2026/09/02 19:04:48 wiz Exp $

DISTNAME=	kcalendarcore-${KF6VER}
PKGREVISION=	1
CATEGORIES=	time

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE calendar access library
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

CMAKE_CONFIGURE_ARGS+=		-DBUILD_PYTHON_BINDINGS=OFF

PKGCONFIG_OVERRIDE+=		_KDE_build/KF6CalendarCore.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../time/libical/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
