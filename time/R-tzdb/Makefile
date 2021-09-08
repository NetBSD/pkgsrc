# $NetBSD: Makefile,v 1.1 2021/09/08 14:55:37 mef Exp $

R_PKGNAME=	tzdb
R_PKGVER=	0.1.2
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Time Zone Database Information
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	c++11
REPLACE_PERL=	inst/tzdata/zoneinfo2tdf.pl

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
