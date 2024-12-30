# $NetBSD: Makefile,v 1.3 2024/12/30 13:44:18 mef Exp $

R_PKGNAME=	googledrive
R_PKGVER=	2.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to Google Drive
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-cli>=3.0.0:../../devel/R-cli
DEPENDS+=	R-gargle-[0-9]*:../../www/R-gargle
DEPENDS+=	R-glue>=1.4.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.1:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.2.3:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.9:../../devel/R-rlang
DEPENDS+=	R-uuid>=0.1.2:../../devel/R-uuid
DEPENDS+=	R-withr>=2.4.2:../../devel/R-withr
DEPENDS+=	R-tibble>=2.0.0:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.3.0:../../math/R-vctrs
DEPENDS+=	R-pillar>=1.6.2:../../misc/R-pillar
DEPENDS+=	R-jsonlite>=1.8.0:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockr-[0-9]*:../../devel/R-mockr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
