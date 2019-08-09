# $NetBSD: Makefile,v 1.1 2019/08/09 19:08:33 brook Exp $

R_PKGNAME=	gh
R_PKGVER=	1.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GitHub API
LICENSE=	mit

DEPENDS+=	R-ini>=0.3.1:../../devel/R-ini
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
