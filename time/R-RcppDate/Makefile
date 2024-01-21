# $NetBSD: Makefile,v 1.1 2024/01/21 08:49:38 mef Exp $

R_PKGNAME=	RcppDate
R_PKGVER=	0.0.3
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	'date' C++ Header Library for Date and Time Functionality
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec

USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++17


.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
