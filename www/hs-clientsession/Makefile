# $NetBSD: Makefile,v 1.3 2024/05/09 01:32:52 pho Exp $

DISTNAME=	clientsession-0.9.2.0
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Securely store session data in a client-side cookie
LICENSE=	mit

# Use crypton instead of outdated cryptonite.
SUBST_CLASSES+=		crypton
SUBST_STAGE.crypton=	post-extract
SUBST_FILES.crypton+=	clientsession.cabal
SUBST_FILES.crypton+=	src/Web/ClientSession.hs
SUBST_SED.crypton=	-e 's/cryptonite/crypton/g'

.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../devel/hs-setenv/buildlink3.mk"
.include "../../security/hs-skein/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
