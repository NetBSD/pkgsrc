# $NetBSD: Makefile,v 1.7 2012/10/08 23:01:05 adam Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
