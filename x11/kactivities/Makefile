# $NetBSD: Makefile,v 1.8 2013/01/26 21:36:53 adam Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
