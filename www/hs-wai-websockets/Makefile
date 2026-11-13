# $NetBSD: Makefile,v 1.13 2026/11/13 14:40:06 pho Exp $

DISTNAME=	wai-websockets-3.0.1.2
PKGREVISION=	10
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
