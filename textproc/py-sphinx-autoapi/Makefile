# $NetBSD: Makefile,v 1.1 2020/04/06 07:38:38 wiz Exp $

DISTNAME=	sphinx-autoapi-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autoapi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/readthedocs/sphinx-autoapi
COMMENT=	Autodoc style documenation for multiple languages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-astroid-[0-9]*:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-Unidecode-[0-9]*:../../textproc/py-Unidecode
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
