# $NetBSD: Makefile,v 1.3 2015/12/05 21:26:06 adam Exp $

DISTNAME=	python-digest-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-digest/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
