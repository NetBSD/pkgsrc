# $NetBSD: Makefile,v 1.16 2025/02/01 14:35:13 pho Exp $

DISTNAME=	warp-tls-3.4.12
CATEGORIES=	www security

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTTP over TLS support for Warp via the TLS package
LICENSE=	mit

.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-streaming-commons/buildlink3.mk"
.include "../../security/hs-tls-session-manager/buildlink3.mk"
.include "../../net/hs-recv/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
