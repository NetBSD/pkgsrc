# $NetBSD: Makefile,v 1.1 2015/07/15 18:49:39 wiz Exp $

DISTNAME=	Routes-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://pypi.python.org/packages/source/R/Routes/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/Routes
COMMENT=	Python re-implementation of the Rails routes system for mapping URLs
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-repoze.lru-[0-9]*:../../devel/py-repoze.lru

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
