# $NetBSD: Makefile,v 1.16 2009/08/22 12:01:21 obache Exp $

DISTNAME=	http_load-12mar2006
PKGNAME=	http_load-20060312
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
