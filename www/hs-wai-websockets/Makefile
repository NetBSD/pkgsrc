# $NetBSD: Makefile,v 1.12 2025/08/13 11:07:45 pho Exp $

DISTNAME=	wai-websockets-3.0.1.2
PKGREVISION=	9
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide a bridge between WAI and the websockets package
LICENSE=	mit

# Don't build or install an example executable.
CONFIGURE_ARGS+=	-f-example

.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-websockets/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
