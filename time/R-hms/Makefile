# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:58 brook Exp $

R_PKGNAME=	hms
R_PKGVER=	0.5.0
CATEGORIES=	time sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pretty time of day
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
