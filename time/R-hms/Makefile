# $NetBSD: Makefile,v 1.5 2023/06/27 13:00:21 mef Exp $

R_PKGNAME=	hms
R_PKGVER=	1.1.3
CATEGORIES=	time sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pretty time of day
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.3.8:../../math/R-vctrs
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle

TEST_DEPENDS+=	R-ellipsis>=0.3.2:../../math/R-ellipsis
TEST_DEPENDS+=	R-lubridate-[0-9]*:../../time/R-lubridate
TEST_DEPENDS+=	R-pillar-[0-9]*:../../misc/R-pillar
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
