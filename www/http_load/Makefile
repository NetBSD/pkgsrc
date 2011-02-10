# $NetBSD: Makefile,v 1.19 2011/02/10 12:36:31 obache Exp $

DISTNAME=	http_load-12mar2006
PKGNAME=	http_load-20060312
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
