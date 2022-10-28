# $NetBSD: Makefile,v 1.4 2022/10/28 09:43:22 adam Exp $

DISTNAME=	openapi-core-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/openapi-core
COMMENT=	Client-side and server-side support for the OpenAPI Specification v3
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=0.1.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy-[0-9]*:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-more-itertools-[0-9]*:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.3.0:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-openapi-spec-validator>=0.5.0:../../textproc/py-openapi-spec-validator
DEPENDS+=	${PYPKGPREFIX}-parse-[0-9]*:../../textproc/py-parse
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
TEST_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-falcon-[0-9]*:../../devel/py-falcon
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
