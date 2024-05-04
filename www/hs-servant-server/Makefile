# $NetBSD: Makefile,v 1.6 2024/05/04 13:31:29 pho Exp $

DISTNAME=	servant-server-0.20
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Family of combinators for defining webservices APIs and serving them
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base		\
	bytestring	\
	constraints	\
	http-api-data	\
	network		\
	text

.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-constraints/buildlink3.mk"
.include "../../www/hs-http-api-data/buildlink3.mk"
.include "../../www/hs-http-media/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-monad-control/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../www/hs-servant/buildlink3.mk"
.include "../../devel/hs-sop-core/buildlink3.mk"
.include "../../converters/hs-string-conversions/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-app-static/buildlink3.mk"
.include "../../devel/hs-word8/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
