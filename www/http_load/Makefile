# $NetBSD: Makefile,v 1.2 2002/07/02 16:26:30 wiz Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	multiprocessing http test client

MAKE_ENV+=	SSLBASE="${SSLBASE}"

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
