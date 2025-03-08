# $NetBSD: Makefile,v 1.6 2025/03/08 05:13:51 pho Exp $

DISTNAME=	http-client-restricted-0.1.0
PKGREVISION=	5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Restricting the servers that http-client will use
LICENSE=	mit

.include "../../net/hs-crypton-connection/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
