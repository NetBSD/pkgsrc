# $NetBSD: Makefile,v 1.14 2021/02/13 08:01:01 mef Exp $

DISTNAME=	HTTP-4000.3.14
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell library for client-side HTTP
LICENSE=	modified-bsd

BUILDLINK_API_DEPENDS.ghc+=	ghc<9.0
.include "../../mk/haskell.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
