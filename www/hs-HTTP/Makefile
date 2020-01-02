# $NetBSD: Makefile,v 1.12 2020/01/02 15:50:01 pho Exp $

DISTNAME=	HTTP-4000.3.14
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell library for client-side HTTP
LICENSE=	modified-bsd

.include "../../mk/haskell.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
