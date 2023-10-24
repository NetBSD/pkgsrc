# $NetBSD: Makefile,v 1.19 2023/10/24 22:11:41 wiz Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	6
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

.include "../../devel/kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
