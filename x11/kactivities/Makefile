# $NetBSD: Makefile,v 1.22 2014/02/12 23:18:48 tron Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

INSTALLATION_DIRS= share/kde/config

post-install:
	${INSTALL_DATA} ${FILESDIR}/activitymanagerrc ${DESTDIR}${PREFIX}/share/kde/config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../misc/nepomuk-core/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
