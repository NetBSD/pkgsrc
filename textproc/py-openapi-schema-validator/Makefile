# $NetBSD: Makefile,v 1.11 2025/09/28 19:55:22 wiz Exp $

DISTNAME=	openapi_schema_validator-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-schema-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openapi/openapi-schema-validator
COMMENT=	OpenAPI schema validation for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.19.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema-specifications>=2023.5.2:../../textproc/py-jsonschema-specifications
DEPENDS+=	${PYPKGPREFIX}-rfc3339-validator-[0-9]*:../../time/py-rfc3339-validator
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
