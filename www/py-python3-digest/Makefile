# $NetBSD: Makefile,v 1.3 2014/12/31 13:57:34 wiz Exp $

DISTNAME=	python3-digest-1.8b4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python3/python/}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/p/python3-digest/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	26 27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
