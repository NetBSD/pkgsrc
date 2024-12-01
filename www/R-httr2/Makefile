# $NetBSD: Makefile,v 1.2 2024/12/01 18:55:25 wiz Exp $

R_PKGNAME=	httr2
R_PKGVER=	1.0.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perform HTTP Requests and Process the Responses
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-glue>=1.8.0:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.4:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=2.0.3:../../devel/R-magrittr
DEPENDS+=	R-rappdirs>=0.3.3:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=1.1.0:../../devel/R-rlang
DEPENDS+=	R-withr>=3.0.1:../../devel/R-withr
DEPENDS+=	R-vctrs>=0.6.3:../../math/R-vctrs
DEPENDS+=	R-openssl>=2.0.5nb1:../../security/R-openssl
#DEPENDS+=	R-curl>=6.0.1:../../www/R-curl
DEPENDS+=	R-curl-[0-9]*:../../www/R-curl

# Packages suggested but not available: 'docopt', 'paws.common'
#
# Package required and available but unsuitable version: 'later'
#
TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-clipr-[0-9]*:../../devel/R-clipr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
TEST_DEPENDS+=	R-jose-[0-9]*:../../security/R-jose
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-later-[0-9]*:../../sysutils/R-later
TEST_DEPENDS+=	R-promises-[0-9]*:../../parallel/R-promises
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../devel/R-cli/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
