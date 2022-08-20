# $NetBSD: Makefile,v 1.5 2022/08/20 08:08:23 wiz Exp $

DISTNAME=	http-conduit-2.3.8
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pho@cielonegro.org
COMMENT=	HTTP client package with conduit interface and HTTPS support
LICENSE=	modified-bsd

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
