# $NetBSD: Makefile,v 1.2 2023/11/02 06:37:45 pho Exp $

DISTNAME=	http-client-restricted-0.1.0
PKGREVISION=	1
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
