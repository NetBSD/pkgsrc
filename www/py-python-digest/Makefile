# $NetBSD: Makefile,v 1.9 2018/07/03 05:03:40 adam Exp $

DISTNAME=	python-digest-1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/akoha/python-digest/
COMMENT=	Python library to aid in implementing HTTP Digest Authentication
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
