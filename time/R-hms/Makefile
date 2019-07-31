# $NetBSD: Makefile,v 1.1 2019/07/31 13:56:46 brook Exp $

CATEGORIES=	time sysutils R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/hms/
COMMENT=	Pretty time of day
LICENSE=	gnu-gpl-v3

R_PKGNAME=	hms
R_PKGVER=	0.5.0

DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
