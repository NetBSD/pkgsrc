# $NetBSD: Makefile,v 1.10 2023/03/12 07:20:54 mef Exp $

R_PKGNAME=	httpuv
R_PKGVER=	1.6.9
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTTP and WebSocket server library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-BH>=1.69.0.1:../../devel/R-BH
DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-promises>=1.0.1:../../parallel/R-promises

# Package suggested but not available: 'websocket'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
