# $NetBSD: Makefile,v 1.2 2021/08/24 11:27:50 mef Exp $

R_PKGNAME=	rvest
R_PKGVER=	1.0.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-selectr>=0.4.2:../../textproc/R-selectr
DEPENDS+=	R-xml2>=1.2.2nb1:../../textproc/R-xml2
DEPENDS+=	R-httr>=0.5:../../www/R-httr

# Packages suggested but not available: 'repurrrsive', 'webfakes'
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
