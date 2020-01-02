# $NetBSD: Makefile,v 1.7 2020/01/02 16:52:57 pho Exp $

DISTNAME=	X11-xft-0.3.1
PKGREVISION=	4
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Bindings to the Xft library, and some Xrender parts
LICENSE=	gnu-gpl-v2

# Work around a Cabal bug. It ignores "ld-options" in
# {package}.buildinfo while linking shared libraries:
# https://github.com/haskell/cabal/issues/4925
HASKELL_ENABLE_SHARED_LIBRARY= no

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
