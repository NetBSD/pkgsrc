# $NetBSD: Makefile,v 1.17 2025/03/05 03:40:09 pho Exp $

DISTNAME=	http-client-tls-0.3.6.4
PKGREVISION=	2
CATEGORIES=	www security

MAINTAINER=	pho@cielonegro.org
COMMENT=	TLS backend for Haskell http-client library
LICENSE=	mit

.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
