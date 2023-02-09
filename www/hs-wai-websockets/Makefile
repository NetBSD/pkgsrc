# $NetBSD: Makefile,v 1.5 2023/02/09 14:34:55 pho Exp $

DISTNAME=	wai-websockets-3.0.1.2
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide a bridge between WAI and the websockets package
LICENSE=	mit

CONFIGURE_ARGS+=	-f-example

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-websockets/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
