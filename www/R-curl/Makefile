# $NetBSD: Makefile,v 1.45 2026/05/15 10:03:55 wiz Exp $

R_PKGNAME=	curl
R_PKGVER=	7.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

# Package suggested but not available: 'webutils'

TEST_DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-later-[0-9]*:../../sysutils/R-later
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
#TEST_DEPENDS+=	R-webutils-[0-9]*:../../www/R-webutils

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
BUILDLINK_API_DEPENDS.curl+=	curl>=7.73
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
