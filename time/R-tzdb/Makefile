# $NetBSD: Makefile,v 1.3 2023/06/27 13:07:54 mef Exp $

R_PKGNAME=	tzdb
R_PKGVER=	0.4.0
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Time Zone Database Information
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c++11
REPLACE_PERL=	inst/tzdata/zoneinfo2tdf.pl

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
