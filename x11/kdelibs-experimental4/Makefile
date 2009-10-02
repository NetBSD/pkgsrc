# $NetBSD: Makefile,v 1.1.1.1 2009/10/02 19:23:22 markd Exp $

DISTNAME=	kdelibs-experimental-${_KDE_VERSION}
CATEGORIES=	x11
COMMENT=	Experimental libraries for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde4/Makefile.kde4"

PKG_DESTDIR_SUPPORT=	user-destdir

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
