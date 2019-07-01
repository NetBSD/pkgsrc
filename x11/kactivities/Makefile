# $NetBSD: Makefile,v 1.46 2019/07/01 04:07:53 ryoon Exp $

DISTNAME=	kactivities-4.13.3
PKGREVISION=	14
CATEGORIES=	x11
COMMENT=	KDE Activity Manager
MASTER_SITES=	${MASTER_SITE_KDE:=4.13.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

DEPENDS+=	libkactivities4-[0-9]*:../../x11/libkactivities4

DISTINFO_FILE=	${.CURDIR}/../../x11/libkactivities4/distinfo

# Needs C++11 features for kactivitymanager
GCC_REQD+=	4.5

CMAKE_ARGS+=	-DWITH_NepomukCore:BOOL=OFF

# The default MACOSX_DEPLOYMENT_TARGET is incompatible with the C++11 tests.
CMAKE_ARGS.Darwin+=	-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=${OSX_VERSION}

INSTALLATION_DIRS= bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_KDE_build/src/service/kactivitymanagerd ${DESTDIR}${PREFIX}/bin/kactivitymanagerd

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
