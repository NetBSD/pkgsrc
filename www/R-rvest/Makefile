# $NetBSD: Makefile,v 1.1 2020/08/07 01:57:55 brook Exp $

R_PKGNAME=	rvest
R_PKGVER=	0.3.5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-selectr>=0.4.2:../../textproc/R-selectr
DEPENDS+=	R-xml2>=1.2.2nb1:../../textproc/R-xml2
DEPENDS+=	R-httr>=0.5:../../www/R-httr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
