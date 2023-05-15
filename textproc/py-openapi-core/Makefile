# $NetBSD: Makefile,v 1.5 2023/05/15 20:33:32 adam Exp $

DISTNAME=	openapi_core-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openapi/openapi-core
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-jsonschema-spec>=0.1.1:../../textproc/py-jsonschema-spec
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy-[0-9]*:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.4.2:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-openapi-spec-validator>=0.5.0:../../textproc/py-openapi-spec-validator
DEPENDS+=	${PYPKGPREFIX}-pathable>=0.4.0:../../devel/py-pathable
DEPENDS+=	${PYPKGPREFIX}-parse-[0-9]*:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django3
TEST_DEPENDS+=	${PYPKGPREFIX}-falcon-[0-9]*:../../devel/py-falcon
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
# TODO: starlette>=0.26.1
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
