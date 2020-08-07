# $NetBSD: Makefile,v 1.1 2020/08/07 02:33:41 brook Exp $

R_PKGNAME=	lubridate
R_PKGVER=	1.7.4
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Dealing with Dates a Little Easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
