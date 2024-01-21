# $NetBSD: Makefile,v 1.1 2024/01/21 10:35:29 mef Exp $

R_PKGNAME=	nanotime
R_PKGVER=	0.3.7
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nanosecond-Resolution Time Support for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bit64>=4.0.5:../../devel/R-bit64
DEPENDS+=	R-RcppDate-[0-9]*:../../time/R-RcppDate
DEPENDS+=	R-RcppCCTZ-[0-9]*:../../time/R-RcppCCTZ
DEPENDS+=	R-zoo>=1.8.12:../../math/R-zoo

TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts

# !pdfTeX error: pdflatex (file tctt1000): Font tctt1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-pdfpages-[0-9]*:../../print/tex-pdfpages
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../time/R-RcppCCTZ/buildlink3.mk"
.include "../../time/R-RcppDate/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
