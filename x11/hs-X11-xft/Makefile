# $NetBSD: Makefile,v 1.22 2025/02/02 13:06:08 pho Exp $

DISTNAME=	X11-xft-0.3.4
PKGREVISION=	9
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
