# $NetBSD: Makefile,v 1.2 2009/10/11 08:13:40 markd Exp $

DISTNAME=	kdelibs-experimental-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Experimental libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
