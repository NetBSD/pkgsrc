# $NetBSD: Makefile,v 1.4 2022/05/04 12:38:54 mef Exp $

R_PKGNAME=	rvest
R_PKGVER=	1.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-selectr>=0.4.2:../../textproc/R-selectr
DEPENDS+=	R-xml2>=1.3:../../textproc/R-xml2
DEPENDS+=	R-httr>=0.5:../../www/R-httr
DEPENDS+=	R-lifecycle>=1.0.0:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble

# Packages suggested but not available: 'repurrrsive', 'webfakes'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
TEST_DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-repurrrsive-[0-9]*:../../math/R-repurrrsive
TEST_DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-selectr-[0-9]*:../../textproc/R-selectr
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-stringi-[0-9]*:../../textproc/R-stringi
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-webfakes-[0-9]*:../../www/R-webfakes
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
