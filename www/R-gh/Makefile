# $NetBSD: Makefile,v 1.2 2021/08/24 10:31:18 mef Exp $

R_PKGNAME=	gh
R_PKGVER=	1.3.0
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GitHub API
LICENSE=	mit

DEPENDS+=	R-ini>=0.3.1:../../devel/R-ini
DEPENDS+=	R-jsonlite>=1.6:../../textproc/R-jsonlite
DEPENDS+=	R-httr>=1.4.1:../../www/R-httr
DEPENDS+=	R-gitcreds-[0-9]*:../../security/R-gitgreds
DEPENDS+=	R-cli>=2.0.1:../../devel/R-cli

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
