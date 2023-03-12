# $NetBSD: Makefile,v 1.5 2023/03/12 05:51:48 mef Exp $

R_PKGNAME=	htmlwidgets
R_PKGVER=	1.6.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML widgets for R
LICENSE=	mit

DEPENDS+=	R-htmltools>=0.3:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml
DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown>=1.3:../../textproc/R-markdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
