# $NetBSD: Makefile,v 1.2 2022/12/18 08:26:21 jperkin Exp $

R_PKGNAME=	pkgdown
R_PKGVER=	2.0.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Static HTML Documentation for a Package
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-callr>=2.0.2:../../devel/R-callr
DEPENDS+=	R-crayon>=1.5.1:../../devel/R-crayon
DEPENDS+=	R-desc>=1.4.1:../../devel/R-desc
DEPENDS+=	R-fs>=1.4.0:../../devel/R-fs
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-memoise>=2.0.0:../../devel/R-memoise
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang
DEPENDS+=	R-whisker>=0.4:../../devel/R-whisker
DEPENDS+=	R-withr>=2.4.3:../../devel/R-withr
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-jsonlite>=1.8.0:../../textproc/R-jsonlite
DEPENDS+=	R-rmarkdown>=1.1.9007:../../textproc/R-rmarkdown
DEPENDS+=	R-xml2>=1.3.1:../../textproc/R-xml2
DEPENDS+=	R-yaml>=2.2.1:../../textproc/R-yaml
DEPENDS+=	R-bslib>=0.3.1:../../www/R-bslib
DEPENDS+=	R-httr>=1.4.2:../../www/R-httr
DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg
#DEPENDS+=	R-downlit-[0-9]*:../../www/R-downlit

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
