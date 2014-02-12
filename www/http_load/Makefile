# $NetBSD: Makefile,v 1.23 2014/02/12 23:18:45 tron Exp $

DISTNAME=	http_load-12mar2006
PKGNAME=	http_load-20060312
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client
LICENSE=	2-clause-bsd

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SYSV_LIBS="-lnsl -lsocket -lresolv"
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
