# $NetBSD: Makefile,v 1.1 2014/06/02 04:27:32 rodent Exp $

DISTNAME=	python-digest-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-digest/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34
EGG_NAME=			${DISTNAME:S/-/_/1}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
