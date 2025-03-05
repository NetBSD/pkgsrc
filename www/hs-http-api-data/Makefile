# $NetBSD: Makefile,v 1.10 2025/03/05 03:40:09 pho Exp $

DISTNAME=	http-api-data-0.6.1
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Converting to/from HTTP API data
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	hashable

.include "../../www/hs-cookie/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../time/hs-text-iso8601/buildlink3.mk"
.include "../../time/hs-time-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-uuid-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
