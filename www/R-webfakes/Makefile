# $NetBSD: Makefile,v 1.4 2025/01/01 13:24:20 mef Exp $

R_PKGNAME=	webfakes
R_PKGVER=	1.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fake Web Apps for HTTP Testing
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-brotli-[0-9]*:../../archivers/R-brotli
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2
TEST_DEPENDS+=	R-zip-[0-9]*:../../archivers/R-zip

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
