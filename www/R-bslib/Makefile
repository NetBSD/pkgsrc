# $NetBSD: Makefile,v 1.5 2024/12/16 04:39:35 mef Exp $

R_PKGNAME=	bslib
R_PKGVER=	0.8.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Custom 'Bootstrap' 'Sass' Themes for 'shiny' and 'rmarkdown'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-cachem-[0-9]*:../../devel/R-cachem
DEPENDS+=	R-htmltools>=0.5.1:../../textproc/R-htmltools
DEPENDS+=	R-jquerylib-[0-9]*:../../www/R-jquerylib
DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-memoise-[0-9]*:../../devel/R-memoise
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-sass>=0.4.0:../../www/R-sass
DEPENDS+=	R-mime-[0-9]*:../../mail/R-mime

# Package suggested but not available: 'bsicons', 'future'

TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-thematic-[0-9]*:../../graphics/R-thematic

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
