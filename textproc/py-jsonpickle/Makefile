# $NetBSD: Makefile,v 1.28 2026/10/16 19:46:06 adam Exp $

DISTNAME=	jsonpickle-4.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonpickle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jsonpickle.github.io/
COMMENT=	Python library for serializing any arbitrary object graph into JSON
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.0:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-gmpy2>=0:../../math/py-gmpy2
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=0:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-pandas>=0:../../math/py-pandas
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
