# $NetBSD: Makefile,v 1.2 2024/12/30 10:26:11 mef Exp $

R_PKGNAME=	downlit
R_PKGVER=	0.4.4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntax Highlighting and Automatic Linking
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-brio>=1.1.3:../../devel/R-brio
DEPENDS+=	R-desc>=1.4.1:../../devel/R-desc
DEPENDS+=	R-evaluate>=0.15:../../devel/R-evaluate
DEPENDS+=	R-fansi>=0.5.0:../../devel/R-fansi
DEPENDS+=	R-memoise>=2.0.0:../../devel/R-memoise
DEPENDS+=	R-rlang>=1.0.2:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.4.1:../../math/R-vctrs
DEPENDS+=	R-digest>=0.6.25:../../security/R-digest
DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr
DEPENDS+=	R-yaml>=2.2.1:../../textproc/R-yaml

# Package suggested but not available: 'MassSpecWavelet'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
#EST_DEPENDS+=	R-leaflet-[0-9]*:
TEST_DEPENDS+=	R-pkgload-[0-9]*:../../devel/R-pkgload
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
