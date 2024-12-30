# $NetBSD: Makefile,v 1.5 2024/12/30 12:32:34 mef Exp $

R_PKGNAME=	gh
R_PKGVER=	1.4.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GitHub API
LICENSE=	mit

DEPENDS+=	R-cli>=2.0.1:../../devel/R-cli
DEPENDS+=	R-gitcreds-[0-9]*:../../security/R-gitcreds
DEPENDS+=	R-httr2-[0-9]*:../../www/R-httr2
DEPENDS+=	R-ini>=0.3.1:../../devel/R-ini
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat>=2.3.2:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
