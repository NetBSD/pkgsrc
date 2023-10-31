# $NetBSD: Makefile,v 1.1 2023/10/31 06:20:11 pho Exp $

DISTNAME=	DAV-1.3.4
PKGNAME=	hs-${DISTNAME:tl}
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	RFC 4918 WebDAV support
LICENSE=	gnu-gpl-v3

OPTPARSE_APPLICATIVE_EXECUTABLES+=	hdav

# lib:DAV
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-hamlet/buildlink3.mk"

# exe:hdav
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-transformers-base/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
