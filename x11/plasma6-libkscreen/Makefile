# $NetBSD: Makefile,v 1.14 2026/09/06 10:23:33 markd Exp $

DISTNAME=	libkscreen-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://invent.kde.org/plasma/libkscreen
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

USE_PKGLOCALEDIR=	yes

USE_CXX_FEATURES+=	c++23

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
