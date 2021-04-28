# $NetBSD: Makefile,v 1.5 2021/04/28 12:44:52 adam Exp $

DISTNAME=	sphinx-autoapi-1.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autoapi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/readthedocs/sphinx-autoapi
COMMENT=	Autodoc style documenation for multiple languages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-astroid>=2.4:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
