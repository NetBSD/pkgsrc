# $NetBSD: Makefile,v 1.12 2026/07/07 13:06:01 adam Exp $

DISTNAME=	openapi_schema_validator-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-schema-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openapi/openapi-schema-validator
COMMENT=	OpenAPI schema validation for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.19.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema-specifications>=2024.10.1:../../textproc/py-jsonschema-specifications
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-pydantic-settings>=2.0.0:../../devel/py-pydantic-settings
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.37.0:../../textproc/py-referencing
DEPENDS+=	${PYPKGPREFIX}-rfc3339-validator-[0-9]*:../../time/py-rfc3339-validator
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
