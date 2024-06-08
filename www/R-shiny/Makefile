# $NetBSD: Makefile,v 1.8 2024/06/08 13:02:38 mef Exp $

R_PKGNAME=	shiny
R_PKGVER=	1.8.1.1
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

# Packages required but not available:
#  'httpuv', 'mime', 'xtable', 'fontawesome', 'htmltools',
#  'sourcetools', 'later', 'promises', 'fastmap', 'commonmark', 'bslib',
#  'cachem'
#
# Packages suggested but not available:
#  'DT', 'Cairo', 'knitr', 'markdown', 'rmarkdown', 'ggplot2',
#  'reactlog', 'yaml', 'future', 'dygraphs', 'ragg', 'showtext', 'sass'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
