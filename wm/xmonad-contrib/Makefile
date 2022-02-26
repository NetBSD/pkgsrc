# $NetBSD: Makefile,v 1.16 2022/02/26 03:58:33 pho Exp $

DISTNAME=	xmonad-contrib-0.17.0
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
COMMENT=	Third party extensions for xmonad
LICENSE=	modified-bsd

.include "options.mk"

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../time/hs-old-time/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../wm/xmonad/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
