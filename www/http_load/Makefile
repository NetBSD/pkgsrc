# $NetBSD: Makefile,v 1.28 2025/04/12 07:04:18 adam Exp $

DISTNAME=	http_load-09Mar2016
PKGNAME=	http_load-20160309
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client
LICENSE=	2-clause-bsd

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

MAKE_ENV.SunOS+=	SYSV_LIBS="-lnsl -lsocket -lresolv"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
