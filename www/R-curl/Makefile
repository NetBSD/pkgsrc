# $NetBSD: Makefile,v 1.32 2024/05/29 16:34:46 adam Exp $

R_PKGNAME=	curl
R_PKGVER=	5.0.0
PKGREVISION=	4
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
