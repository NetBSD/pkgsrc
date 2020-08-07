# $NetBSD: Makefile,v 1.1 2020/08/07 01:54:20 brook Exp $

R_PKGNAME=	RCurl
R_PKGVER=	1.98-1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General Network (HTTP/FTP/...) Client Interface for R
LICENSE=	modified-bsd

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../math/R-bitops/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
