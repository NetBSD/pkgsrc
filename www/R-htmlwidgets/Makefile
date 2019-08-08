# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:58 brook Exp $

R_PKGNAME=	htmlwidgets
R_PKGVER=	1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML widgets for R
LICENSE=	mit

DEPENDS+=	R-htmltools>=0.3:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
