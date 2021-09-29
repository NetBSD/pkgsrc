# $NetBSD: Makefile,v 1.5 2021/09/29 19:01:25 adam Exp $

R_PKGNAME=	RCurl
R_PKGVER=	1.98-1.5
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General Network (HTTP/FTP/...) Client Interface for R
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../math/R-bitops/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
