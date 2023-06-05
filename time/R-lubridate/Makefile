# $NetBSD: Makefile,v 1.3 2023/06/05 12:25:59 mef Exp $

R_PKGNAME=	lubridate
R_PKGVER=	1.9.2
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Dealing with Dates a Little Easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-generics-[0-9]*:../../math/R-generics
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-timechange-[0-9]*:../../time/R-timechange

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
