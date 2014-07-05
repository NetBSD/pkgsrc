# $NetBSD: Makefile,v 1.2 2014/07/05 23:23:14 rodent Exp $

DISTNAME=	furl-0.3.94
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/f/furl/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/gruns/furl
COMMENT=	URL manipulation made simple
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-orderedmultidict>=0.7.1:../../databases/py-orderedmultidict

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	unittest2

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
