# $NetBSD: Makefile,v 1.9 2004/03/26 02:27:58 wiz Exp $
#

DISTNAME=	psycopg-1.0.14
PKGNAME=	zope25-ZPsycopgDA-1.0.14
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Zope

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=	yes
ZOPE_COPYPRODUCT=	zope-std-copyproduct-short

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
