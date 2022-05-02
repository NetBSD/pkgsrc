# $NetBSD: Makefile,v 1.2 2022/05/02 14:19:29 mef Exp $

R_PKGNAME=	diffviewer
R_PKGVER=	0.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML Widget to Show File Differences
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
