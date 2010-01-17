# $NetBSD: Makefile,v 1.3 2010/01/17 12:02:57 wiz Exp $

DISTNAME=	kdelibs-experimental-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Experimental libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
