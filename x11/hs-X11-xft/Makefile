# $NetBSD: Makefile,v 1.21 2024/05/09 01:32:57 pho Exp $

DISTNAME=	X11-xft-0.3.4
PKGREVISION=	8
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
