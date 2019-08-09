# $NetBSD: Makefile,v 1.1 2019/08/09 20:52:49 brook Exp $

R_PKGNAME=	shiny
R_PKGVER=	1.3.2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Web application framework for R
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-sourcetools>=0.1.7:../../lang/R-sourcetools
DEPENDS+=	R-mime>=0.3:../../mail/R-mime
DEPENDS+=	R-xtable>=1.8.4:../../math/R-xtable
DEPENDS+=	R-promises>=1.0.1:../../parallel/R-promises
DEPENDS+=	R-digest>=0.6.20:../../security/R-digest
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-jsonlite>=0.9.16:../../textproc/R-jsonlite
DEPENDS+=	R-httpuv>=1.5.0:../../www/R-httpuv

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../sysutils/R-later/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
