# $NetBSD: Makefile,v 1.1.1.1 2002/10/25 15:00:15 drochner Exp $
#

DISTNAME=	psycopg-1.0.13
PKGNAME=	zope25-ZPsycopgDA-1.0.13
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Zope

USE_BUILDLINK2=	yes
ZOPE_COPYPRODUCT=	zope-std-copyproduct-short
WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
