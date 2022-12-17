# $NetBSD: Makefile,v 1.1 2022/12/17 15:15:53 mef Exp $

R_PKGNAME=	urlchecker
R_PKGVER=	1.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Run CRAN URL Checks from Older R Versions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-cli>=3.4.1:../../devel/R-cli
DEPENDS+=	R-xml2>=1.3.2nb4:../../textproc/R-xml2
DEPENDS+=	R-curl>=4.3.2nb3:../../www/R-curl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
