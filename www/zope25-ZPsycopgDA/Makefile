# $NetBSD: Makefile,v 1.5 2003/05/05 19:05:24 jmmv Exp $
#

DISTNAME=	psycopg-1.0.14
PKGNAME=	zope25-ZPsycopgDA-1.0.14
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Zope

USE_BUILDLINK2=	yes
ZOPE_COPYPRODUCT=	zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
