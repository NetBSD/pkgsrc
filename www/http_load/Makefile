# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:26 tv Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

MAKE_ENV+=	SSLBASE="${SSLBASE}"
USE_BUILDLINK3=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
