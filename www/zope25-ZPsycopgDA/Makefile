# $NetBSD: Makefile,v 1.10 2004/04/16 17:21:34 drochner Exp $
#

DISTNAME=	psycopg-1.1.11
PKGNAME=	zope25-ZPsycopgDA-1.1.11
CATEGORIES=	www
MASTER_SITES=	http://initd.org/pub/software/psycopg/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://initd.org/software/psycopg
COMMENT=	PostgreSQL database adapter for Zope

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_BUILDLINK2=	yes

.include "../../www/zope25/product.mk"
.include "../../databases/py-psycopg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
