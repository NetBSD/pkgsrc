# $NetBSD: Makefile,v 1.2 2021/05/30 15:56:22 mef Exp $

R_PKGNAME=	lubridate
R_PKGVER=	1.7.10
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Dealing with Dates a Little Easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-generics-[0-9]*:../../math/R-generics

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
