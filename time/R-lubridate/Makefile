# $NetBSD: Makefile,v 1.5 2025/01/11 14:06:01 mef Exp $

R_PKGNAME=	lubridate
R_PKGVER=	1.9.4
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Make Dealing with Dates a Little Easier
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-generics-[0-9]*:../../math/R-generics
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr
DEPENDS+=	R-timechange-[0-9]*:../../time/R-timechange

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
