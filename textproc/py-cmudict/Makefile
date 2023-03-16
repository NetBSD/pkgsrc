# $NetBSD: Makefile,v 1.6 2023/03/16 00:11:52 gutteridge Exp $

DISTNAME=	cmudict-1.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmudict/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/prosegrinder/python-cmudict
COMMENT=	Versioned Python wrapper package for cmudict
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# The upstream project lists higher minimums for these depenencies, but that
# is incorrect. What's recorded below are correct minimums for the actual
# functionality required. This has been tested with Python 3.8 and 3.9.
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 38 || ${_PYTHON_VERSION} == 39
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.6:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.0:../../devel/py-importlib-resources
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
