# $NetBSD: Makefile,v 1.10 2026/01/07 08:49:39 wiz Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://invent.kde.org/plasma/libkscreen
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

USE_PKGLOCALEDIR=	yes

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
