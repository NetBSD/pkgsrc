# $NetBSD: Makefile,v 1.4 2025/01/01 02:24:14 mef Exp $

R_PKGNAME=	pkgdown
R_PKGVER=	2.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Static HTML Documentation for a Package
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-bslib>=0.5.1:../../www/R-bslib
DEPENDS+=	R-callr>=2.0.2:../../devel/R-callr
DEPENDS+=	R-crayon>=1.5.1:../../devel/R-crayon
DEPENDS+=	R-desc>=1.4.1:../../devel/R-desc
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-downlit-[0-9]*:../../www/R-downlit
DEPENDS+=	R-fontawesome-[0-9]*:../../textproc/R-fontawesome
DEPENDS+=	R-fs>=1.4.0:../../devel/R-fs
DEPENDS+=	R-httr2-[0-9]*:../../www/R-httr2
DEPENDS+=	R-jsonlite>=1.8.0:../../textproc/R-jsonlite
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-memoise>=2.0.0:../../devel/R-memoise
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang
DEPENDS+=	R-rmarkdown>=2.2.7:../../textproc/R-rmarkdown
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble
DEPENDS+=	R-whisker>=0.4:../../devel/R-whisker
DEPENDS+=	R-withr>=2.4.3:../../devel/R-withr
DEPENDS+=	R-xml2>=1.3.1:../../textproc/R-xml2
DEPENDS+=	R-yaml>=2.2.1:../../textproc/R-yaml
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr

# Packages suggested but not available:
#   'gt', 'quarto', 'rsconnect', 'rticles'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-diffviewer-[0-9]*:../../www/R-diffviewer
TEST_DEPENDS+=	R-gert-[0-9]*:../../devel/R-gert
TEST_DEPENDS+=	R-htmlwidgets-[0-9]*:../../www/R-htmlwidgets
TEST_DEPENDS+=	R-magick-[0-9]*:../../graphics/R-magick
TEST_DEPENDS+=	R-pkgload-[0-9]*:../../devel/R-pkgload
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
