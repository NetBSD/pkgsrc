# $NetBSD: Makefile,v 1.2 2021/04/21 13:25:28 adam Exp $

R_PKGNAME=	RCurl
R_PKGVER=	1.98-1.1
PKGREVISION=	1
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
