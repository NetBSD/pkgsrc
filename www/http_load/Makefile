# $NetBSD: Makefile,v 1.3 2002/10/25 09:33:36 wiz Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	multiprocessing http test client

MAKE_ENV+=	SSLBASE="${SSLBASE}"
USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
