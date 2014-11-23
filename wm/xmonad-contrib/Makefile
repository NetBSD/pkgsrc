# $NetBSD: Makefile,v 1.4 2014/11/23 12:52:33 szptvlfn Exp $

DISTNAME=	xmonad-contrib-0.11.3
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
COMMENT=	Third party extensions for xmonad
LICENSE=	modified-bsd

.include "options.mk"

.include "../../mk/haskell.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../wm/xmonad/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
