# $NetBSD: Makefile,v 1.1 2019/08/09 20:54:29 brook Exp $

R_PKGNAME=	miniUI
R_PKGVER=	0.1.1.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Shiny UI widgets for small screens
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-htmltools>=0.3:../../textproc/R-htmltools
DEPENDS+=	R-shiny>=0.13:../../www/R-shiny

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
