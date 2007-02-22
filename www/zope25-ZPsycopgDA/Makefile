# $NetBSD: Makefile,v 1.18 2007/02/22 19:01:27 wiz Exp $
#

DISTNAME=	psycopg-1.1.21
PKGNAME=	zope25-ZPsycopgDA-1.1.21
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://initd.org/projects/psycopg1/
COMMENT=	PostgreSQL database adapter for Zope

WRKSRC=		${WRKDIR}/${DISTNAME}

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
