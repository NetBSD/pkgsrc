# $NetBSD: Makefile,v 1.3 2023/06/04 02:02:23 mef Exp $

R_PKGNAME=	shinyjs
R_PKGVER=	2.1.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily improve the user experience of your Shiny apps in seconds
LICENSE=	gnu-agpl-v3

DEPENDS+=	R-digest>=0.6.8:../../security/R-digest
DEPENDS+=	R-htmltools>=0.2.9:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-shiny>=1.0.0:../../www/R-shiny

#TEST_DEPENDS+=	R-shinyAce-[0-9]*:
#TEST_DEPENDS+=	R-shinydisconnect-[0-9]*:

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
