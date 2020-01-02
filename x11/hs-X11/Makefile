# $NetBSD: Makefile,v 1.5 2020/01/02 16:48:30 pho Exp $

DISTNAME=	X11-1.9.1
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Haskell binding to the X11 graphics library
LICENSE=	modified-bsd

# Work around a Cabal bug. It ignores "ld-options" in X11.buildinfo
# while linking shared libraries:
# https://github.com/haskell/cabal/issues/4925
HASKELL_ENABLE_SHARED_LIBRARY= no

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
