# $NetBSD: Makefile,v 1.13 2006/03/04 21:30:58 jlam Exp $

DISTNAME=	http_load-04jan2002
PKGNAME=	http_load-20020104
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
