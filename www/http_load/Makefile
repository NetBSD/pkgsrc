# $NetBSD: Makefile,v 1.8 2004/08/04 12:21:02 cube Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

MAKE_ENV+=	SSLBASE="${SSLBASE}"
USE_BUILDLINK3=	YES

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
