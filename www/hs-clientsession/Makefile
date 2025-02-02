# $NetBSD: Makefile,v 1.4 2025/02/02 03:04:20 pho Exp $

DISTNAME=	clientsession-0.9.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Securely store session data in a client-side cookie
LICENSE=	mit

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../security/hs-skein/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-setenv/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
