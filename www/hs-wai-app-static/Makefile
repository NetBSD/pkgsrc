# $NetBSD: Makefile,v 1.2 2023/02/07 01:41:19 pho Exp $

DISTNAME=	wai-app-static-3.1.7.4
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	WAI application for static serving
LICENSE=	mit

# lib:wai-app-static
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../www/hs-http-date/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-extra/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"

# exe:warp
.include "../../net/hs-mime-types/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
