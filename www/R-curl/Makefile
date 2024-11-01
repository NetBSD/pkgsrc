# $NetBSD: Makefile,v 1.34 2024/11/01 12:54:47 wiz Exp $

R_PKGNAME=	curl
R_PKGVER=	5.0.0
PKGREVISION=	6
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
