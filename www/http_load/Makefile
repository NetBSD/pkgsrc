# $NetBSD: Makefile,v 1.27 2023/10/24 22:11:27 wiz Exp $

DISTNAME=	http_load-12mar2006
PKGNAME=	http_load-20060312
PKGREVISION=	7
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
