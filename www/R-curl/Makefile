# $NetBSD: Makefile,v 1.19 2020/05/06 14:05:04 adam Exp $

R_PKGNAME=	curl
R_PKGVER=	4.2
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../math/R/Makefile.extension"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
