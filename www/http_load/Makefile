# $NetBSD: Makefile,v 1.17 2010/01/17 12:02:49 wiz Exp $

DISTNAME=	http_load-12mar2006
PKGNAME=	http_load-20060312
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_load/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acme.com/software/http_load/
COMMENT=	Multiprocessing http test client

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SSLBASE=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
