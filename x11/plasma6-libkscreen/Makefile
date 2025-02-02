# $NetBSD: Makefile,v 1.5 2025/02/02 09:21:15 wiz Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	3
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
