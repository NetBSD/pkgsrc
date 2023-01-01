# $NetBSD: Makefile,v 1.2 2023/01/01 01:01:15 mef Exp $

R_PKGNAME=	webfakes
R_PKGVER=	1.1.6
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Fake Web Apps for HTTP Testing
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-httpuv-[0-9]*:../../www/R-httpuv
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
