# $NetBSD: Makefile,v 1.75 2024/05/29 16:35:00 adam Exp $

DISTNAME=	kactivities-4.13.3
PKGREVISION=	41
CATEGORIES=	x11
COMMENT=	KDE Activity Manager
MASTER_SITES=	${MASTER_SITE_KDE:=4.13.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

DEPENDS+=	libkactivities4-[0-9]*:../../x11/libkactivities4

DISTINFO_FILE=	${.CURDIR}/../../x11/libkactivities4/distinfo

USE_CXX_FEATURES+=	c++11

CMAKE_ARGS+=	-DWITH_NepomukCore:BOOL=OFF

# The default MACOSX_DEPLOYMENT_TARGET is incompatible with the C++11 tests.
CMAKE_ARGS.Darwin+=	-DCMAKE_OSX_DEPLOYMENT_TARGET:STRING=${OSX_VERSION}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_KDE_build/src/service/kactivitymanagerd ${DESTDIR}${PREFIX}/bin/kactivitymanagerd

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
