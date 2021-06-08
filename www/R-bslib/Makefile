# $NetBSD: Makefile,v 1.1 2021/06/08 01:56:05 mef Exp $

R_PKGNAME=	bslib
R_PKGVER=	0.2.5.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Custom 'Bootstrap' 'Sass' Themes for 'shiny' and 'rmarkdown'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-htmltools>=0.5.1:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-sass>=0.4.0:../../www/R-sass
DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib

# Packages suggested but not available: 'rmarkdown', 'thematic'

TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-thematic-[0-9]*:../../graphics/R-thematic
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
