# $NetBSD: Makefile,v 1.4 2024/12/15 08:49:16 mef Exp $

R_PKGNAME=	sass
R_PKGVER=	0.4.9
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Syntactically Awesome Style Sheets ('Sass')
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-fs>=1.5.0:../../devel/R-fs
DEPENDS+=	R-rappdirs>=0.3.1:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=0.4.10:../../devel/R-rlang
DEPENDS+=	R-htmltools>=0.5.1:../../textproc/R-htmltools
DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
DEPENDS+=	R-rappdirs-[0-9]*:../../devel/R-rappdirs
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6

TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
