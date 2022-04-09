# $NetBSD: Makefile,v 1.3 2022/04/09 07:40:34 adam Exp $

DISTNAME=	openapi-schema-validator-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-schema-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/openapi-schema-validator
COMMENT=	OpenAPI schema validation for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3:../../textproc/py-jsonschema

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
