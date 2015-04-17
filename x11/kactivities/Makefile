# $NetBSD: Makefile,v 1.31 2015/04/17 15:52:58 adam Exp $

DISTNAME=	kactivities-4.13.3
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	KDE Activity Manager
MASTER_SITES=	${MASTER_SITE_KDE:=4.13.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

# Needs C++11 features for kactivitymanager
GCC_REQD+=	4.5

CMAKE_ARGS+=	-DWITH_NepomukCore:BOOL=OFF

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

INSTALLATION_DIRS= share/kde/config

post-install:
	${INSTALL_DATA} ${FILESDIR}/activitymanagerrc ${DESTDIR}${PREFIX}/share/kde/config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
