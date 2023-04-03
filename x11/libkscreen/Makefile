# $NetBSD: Makefile,v 1.16 2023/04/03 20:21:28 nros Exp $

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
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
