# $NetBSD: Makefile,v 1.9 2013/02/06 23:21:32 jperkin Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
