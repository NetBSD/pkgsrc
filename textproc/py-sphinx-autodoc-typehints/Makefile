# $NetBSD: Makefile,v 1.6 2021/04/16 06:05:43 adam Exp $

DISTNAME=	sphinx-autodoc-typehints-1.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.0:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.1.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.5:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${MAKE_ENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
