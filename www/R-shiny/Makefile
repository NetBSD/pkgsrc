# $NetBSD: Makefile,v 1.9 2025/01/01 12:40:24 mef Exp $

R_PKGNAME=	shiny
R_PKGVER=	1.10.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Web application framework for R
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fontawesome-[0-9]*:../../textproc/R-fontawesome
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-sourcetools>=0.1.7:../../lang/R-sourcetools
DEPENDS+=	R-mime>=0.3:../../mail/R-mime
DEPENDS+=	R-xtable>=1.8.4:../../math/R-xtable
DEPENDS+=	R-promises>=1.0.1:../../parallel/R-promises
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-httpuv>=1.5.0:../../www/R-httpuv
DEPENDS+=	R-fastmap-[0-9]*:../../devel/R-fastmap
DEPENDS+=	R-commonmark-[0-9]*:../../textproc/R-commonmark
DEPENDS+=	R-bslib-[0-9]*:../../www/R-bslib
DEPENDS+=	R-cachem-[0-9]*:../../devel/R-cachem
DEPENDS+=	R-xtable-[0-9]*:../../math/R-xtable
DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-ellipsis-[0-9]*:../../math/R-ellipsis
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

# Packages suggested but not available:
#   'coro', 'reactlog', 'future', 'dygraphs', 'showtext'

# Package required and available but unsuitable version: 'fontawesome'

TEST_DEPENDS+=	R-DT-[0-9]*:../../textproc/R-DT
TEST_DEPENDS+=	R-Cairo-[0-9]*:../../graphics/R-Cairo
#EST_DEPENDS+=	R-future-[0-9]*:../../wip/R-future
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-yaml-[0-9]*:../../textproc/R-yaml
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
