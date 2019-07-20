# $NetBSD: Makefile,v 1.10 2019/07/20 22:46:54 wiz Exp $

PKGREVISION=	2
CATEGORIES=	www R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/curl/
COMMENT=	Modern and flexible web client for R
LICENSE=	mit

R_PKGNAME=	curl
R_PKGVER=	3.2

BUILDLINK_API_DEPENDS.R+=	R>=3.0.0
.include "../../math/R/Makefile.extension"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
