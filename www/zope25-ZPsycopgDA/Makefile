# $NetBSD: Makefile,v 1.12 2004/07/22 18:12:21 drochner Exp $
#

DISTNAME=	psycopg-1.1.14
PKGNAME=	zope25-ZPsycopgDA-1.1.14
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Zope

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=	yes

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
