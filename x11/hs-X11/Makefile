# $NetBSD: Makefile,v 1.2 2014/07/16 21:05:04 szptvlfn Exp $

DISTNAME=	X11-1.6.1.2
PKGREVISION=	1
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Haskell binding to the X11 graphics library
LICENSE=	modified-bsd

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
