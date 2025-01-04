# $NetBSD: Makefile,v 1.6 2025/01/04 14:53:44 mef Exp $

R_PKGNAME=	timeDate
R_PKGVER=	4041.110
CATEGORIES=	time

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Chronological and calendar objects
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
