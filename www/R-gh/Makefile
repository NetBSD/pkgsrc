# $NetBSD: Makefile,v 1.3 2021/08/24 11:07:58 mef Exp $

R_PKGNAME=	gh
R_PKGVER=	1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GitHub API
LICENSE=	mit

DEPENDS+=	R-ini>=0.3.1:../../devel/R-ini
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr
DEPENDS+=	R-gitcreds-[0-9]*:../../security/R-gitgreds
DEPENDS+=	R-cli>=2.0.1:../../devel/R-cli

TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat>=2.3.2:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
