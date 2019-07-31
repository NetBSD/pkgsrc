# $NetBSD: Makefile,v 1.1 2019/07/31 13:58:41 brook Exp $

CATEGORIES=	www R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/htmlwidgets/
COMMENT=	HTML widgets for R
LICENSE=	mit

R_PKGNAME=	htmlwidgets
R_PKGVER=	1.3

DEPENDS+=	R-htmltools>=0.3:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-yaml>=2.2.0:../../textproc/R-yaml

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
