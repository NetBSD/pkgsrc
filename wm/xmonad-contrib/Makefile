# $NetBSD: Makefile,v 1.24 2024/05/09 01:32:51 pho Exp $

DISTNAME=	xmonad-contrib-0.18.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	wm

MAINTAINER=	degroote@NetBSD.org
COMMENT=	Community-maintained extensions for xmonad
LICENSE=	modified-bsd

.include "options.mk"

.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../x11/hs-X11/buildlink3.mk"
.include "../../wm/xmonad/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
