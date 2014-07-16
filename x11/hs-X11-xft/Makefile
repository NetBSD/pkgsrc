# $NetBSD: Makefile,v 1.2 2014/07/16 21:05:04 szptvlfn Exp $

DISTNAME=	X11-xft-0.3.1
PKGREVISION=	1
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Bindings to the Xft library, and some Xrender parts
LICENSE=	gnu-gpl-v2

.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
