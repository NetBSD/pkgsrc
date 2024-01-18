# $NetBSD: Makefile,v 1.5 2024/01/18 14:11:56 mef Exp $

R_PKGNAME=	timeDate
R_PKGVER=	4032.109
CATEGORIES=	time

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Chronological and calendar objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit
# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
#EST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
