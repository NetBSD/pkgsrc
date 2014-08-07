# $NetBSD: Makefile,v 1.3 2014/08/07 02:22:27 rodent Exp $

DISTNAME=	furl-0.3.95
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
