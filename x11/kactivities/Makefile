# $NetBSD: Makefile,v 1.10 2013/02/16 11:19:53 wiz Exp $

DISTNAME=	kactivities-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	x11
COMMENT=	KDE Activity Manager

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKGCONFIG_OVERRIDE+=	lib/libkactivities.pc.cmake

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
