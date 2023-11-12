# $NetBSD: Makefile,v 1.20 2023/11/12 13:24:08 wiz Exp $

DISTNAME=	X11-xft-0.3.4
PKGREVISION=	7
CATEGORIES=	x11 graphics

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Bindings to the Xft library, and some Xrender parts
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
