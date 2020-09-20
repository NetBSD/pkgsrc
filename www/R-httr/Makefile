# $NetBSD: Makefile,v 1.3 2020/09/20 15:23:56 mef Exp $

R_PKGNAME=	httr
R_PKGVER=	1.4.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for working with URLs and HTTP
LICENSE=	mit

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-mime>=0.7:../../mail/R-mime
DEPENDS+=	R-openssl>=0.8:../../security/R-openssl
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-curl>=3.0.0:../../www/R-curl

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
