# $NetBSD: Makefile,v 1.12 2005/12/05 20:51:12 rillig Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
