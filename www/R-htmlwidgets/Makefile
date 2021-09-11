# $NetBSD: Makefile,v 1.4 2021/09/11 01:49:06 mef Exp $

R_PKGNAME=	htmlwidgets
R_PKGVER=	1.5.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML widgets for R
LICENSE=	mit

DEPENDS+=	R-htmltools>=0.3:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
