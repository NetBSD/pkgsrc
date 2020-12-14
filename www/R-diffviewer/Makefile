# $NetBSD: Makefile,v 1.1 2020/12/14 03:23:39 mef Exp $

R_PKGNAME=	diffviewer
R_PKGVER=	0.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML Widget to Show File Differences
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-jsonlite>=1.7.1:../../textproc/R-jsonlite
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
