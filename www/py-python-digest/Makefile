# $NetBSD: Makefile,v 1.7 2017/09/04 18:08:30 wiz Exp $

DISTNAME=	python-digest-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-digest/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
