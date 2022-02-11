# $NetBSD: Makefile,v 1.11 2022/02/11 15:53:34 pho Exp $

DISTNAME=	X11-1.10.2
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Haskell binding to the X11 graphics library
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
