# $NetBSD: Makefile,v 1.3 2025/01/11 14:25:15 mef Exp $

R_PKGNAME=	sftime
R_PKGVER=	0.3.0
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classes and Methods for Simple Feature Objects that Have a Time Column
LICENSE=	apache-1.1 OR apache-2.0

USE_LANGUAGES=	# none

# Packages suggested but not available:
#   'trajectories', 'ncmeta', 'sftrack', 'cubble'
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spacetime-[0-9]*:../../math/R-spacetime
TEST_DEPENDS+=	R-spatstat.geom-[0-9]*:../../geography/R-spatstat.geom
TEST_DEPENDS+=	R-spatstat.linnet-[0-9]*:../../geography/R-spatstat.linnet
TEST_DEPENDS+=	R-stars-[0-9]*:../../geography/R-stars
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs

.include "../../geography/R-sf/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
