# $NetBSD: Makefile,v 1.4 2012/09/07 19:17:48 adam Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
