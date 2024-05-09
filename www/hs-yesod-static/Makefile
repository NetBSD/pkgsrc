# $NetBSD: Makefile,v 1.3 2024/05/09 01:32:57 pho Exp $

DISTNAME=	yesod-static-1.6.1.0
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Static file serving subsite for Yesod Web Framework
LICENSE=	mit

# Use crypton instead of now-outdated cryptonite.
SUBST_CLASSES+=		crypton
SUBST_STAGE.crypton=	post-extract
SUBST_FILES.crypton=	*.cabal
SUBST_SED.crypton=	-e 's/cryptonite/crypton/g'

.include "../../devel/hs-async/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-crypton-conduit/buildlink3.mk"
.include "../../textproc/hs-css-text/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../lang/hjsmin/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-mime-types/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-app-static/buildlink3.mk"
.include "../../www/hs-yesod-core/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
