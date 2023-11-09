# $NetBSD: Makefile,v 1.10 2023/11/09 18:55:58 adam Exp $

DISTNAME=	openapi_spec_validator-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-spec-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openapi/openapi-spec-validator
COMMENT=	OpenAPI 2.0 (aka Swagger) and OpenAPI 3.0 spec validator
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.18.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema-path>=0.3.1:../../textproc/py-jsonschema-path
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.7.1:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.6.0:../../textproc/py-openapi-schema-validator
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.8.0:../../devel/py-importlib-resources
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} openapi-spec-validator openapi-spec-validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
