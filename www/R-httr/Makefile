# $NetBSD: Makefile,v 1.5 2024/12/31 05:55:06 mef Exp $

R_PKGNAME=	httr
R_PKGVER=	1.4.7
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for working with URLs and HTTP
LICENSE=	mit

DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-curl>=3.0.0:../../www/R-curl
DEPENDS+=	R-mime>=0.7:../../mail/R-mime
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-later-[0-9]*:../../sysutils/R-later
DEPENDS+=	R-openssl>=0.8:../../security/R-openssl
DEPENDS+=	R-promises-[0-9]*:../../parallel/R-promises

TEST_DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
TEST_DEPENDS+=	R-R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
TEST_DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mime-[0-9]*:../../mail/R-mime
TEST_DEPENDS+=	R-openssl-[0-9]*:../../security/R-openssl
TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
