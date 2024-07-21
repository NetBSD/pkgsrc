# $NetBSD: Makefile,v 1.1 2024/07/21 20:42:35 markd Exp $

DISTNAME=	libkscreen-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://invent.kde.org/plasma/libkscreen
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

USE_PKGLOCALEDIR=	yes

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
