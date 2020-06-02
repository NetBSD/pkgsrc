# $NetBSD: Makefile,v 1.3 2020/06/02 08:23:05 adam Exp $

DISTNAME=	libkscreen-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma5.mk"

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/kscreen2.pc.in

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

.include "../../devel/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
