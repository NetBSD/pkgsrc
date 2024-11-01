# $NetBSD: Makefile,v 1.14 2024/11/01 00:54:00 wiz Exp $

R_PKGNAME=	RCurl
R_PKGVER=	1.98-1.14
PKGREVISION=	3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General Network (HTTP/FTP/...) Client Interface for R
LICENSE=	modified-bsd

TEST_DEPENDS+=	R-XML-[0-9]*:../../math/R-XML

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../math/R-bitops/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
