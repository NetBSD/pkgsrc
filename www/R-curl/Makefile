# $NetBSD: Makefile,v 1.3 2018/02/02 00:25:41 minskim Exp $

CATEGORIES=	www R
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/curl/
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

R_PKGNAME=	curl
R_PKGVER=	3.1

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
