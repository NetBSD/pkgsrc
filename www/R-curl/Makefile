# $NetBSD: Makefile,v 1.22 2021/04/21 13:25:28 adam Exp $

R_PKGNAME=	curl
R_PKGVER=	4.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
