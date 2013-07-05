# $NetBSD: Makefile,v 1.18 2013/07/05 13:29:44 ryoon Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	4
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
