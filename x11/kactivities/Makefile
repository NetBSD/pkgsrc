# $NetBSD: Makefile,v 1.28 2014/11/07 19:39:26 adam Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

# Needs C++11 features for kactivitymanager
GCC_REQD+=	4.5

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

INSTALLATION_DIRS= share/kde/config

post-install:
	${INSTALL_DATA} ${FILESDIR}/activitymanagerrc ${DESTDIR}${PREFIX}/share/kde/config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
