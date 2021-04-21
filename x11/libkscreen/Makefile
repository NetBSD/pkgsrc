# $NetBSD: Makefile,v 1.7 2021/04/21 11:40:48 adam Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	3
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

.include "../../devel/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
