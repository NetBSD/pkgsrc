# $NetBSD: Makefile,v 1.10 2023/02/07 01:41:20 pho Exp $

DISTNAME=	warp-tls-3.3.4
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	HTTP over TLS support for Warp via the TLS package
LICENSE=	mit

.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../security/hs-tls-session-manager/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
