# $NetBSD: Makefile,v 1.20 2020/06/05 12:49:02 jperkin Exp $

DISTNAME=	kactivities-4.13.3
PKGNAME=	libkactivities4-4.13.3
PKGREVISION=	18
CATEGORIES=	x11
COMMENT=	KDE Activity Manager
MASTER_SITES=	${MASTER_SITE_KDE:=4.13.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

CONFLICTS+=	kactivities<4.13.3nb4

# Needs C++11 features for kactivitymanager
GCC_REQD+=	4.5

CMAKE_ARGS+=	-DWITH_NepomukCore:BOOL=OFF

# The default MACOSX_DEPLOYMENT_TARGET is incompatible with the C++11 tests.
CMAKE_ARGS.Darwin+=	-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=${OSX_VERSION}

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

INSTALLATION_DIRS=	share/kde/config

post-install:
	${INSTALL_DATA} ${FILESDIR}/activitymanagerrc ${DESTDIR}${PREFIX}/share/kde/config
	rm -r ${DESTDIR}${PREFIX}/bin

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
