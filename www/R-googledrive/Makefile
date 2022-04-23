# $NetBSD: Makefile,v 1.1 2022/04/23 06:10:12 mef Exp $

R_PKGNAME=	googledrive
R_PKGVER=	2.0.0
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

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
