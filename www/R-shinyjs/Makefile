# $NetBSD: Makefile,v 1.1 2019/08/09 20:53:39 brook Exp $

R_PKGNAME=	shinyjs
R_PKGVER=	1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily improve the user experience of your Shiny apps in seconds
LICENSE=	gnu-agpl-v3

DEPENDS+=	R-digest>=0.6.8:../../security/R-digest
DEPENDS+=	R-htmltools>=0.2.9:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-shiny>=1.0.0:../../www/R-shiny

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
