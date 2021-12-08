# $NetBSD: Makefile,v 1.25 2021/12/08 16:06:53 adam Exp $

R_PKGNAME=	curl
R_PKGVER=	4.3.2
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

#TEST_DEPENDS+=	R-webutils[0-9]*:../../www/R-webutils

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
