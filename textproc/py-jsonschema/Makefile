# $NetBSD: Makefile,v 1.41 2024/05/08 08:23:39 adam Exp $

DISTNAME=	jsonschema-4.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-attrs>=22.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-jsonschema-specifications>=2023.03.6:../../textproc/py-jsonschema-specifications
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.28.4:../../textproc/py-referencing
DEPENDS+=	${PYPKGPREFIX}-rpds-py>=0.7.1:../../devel/py-rpds-py
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 309
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.4.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-pkgutil_resolve_name>=1.3.10:../../devel/py-pkgutil_resolve_name
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jsonschema jsonschema-${PYVERSSUFFIX} || ${TRUE}

TEST_ENV+=	JSON_SCHEMA_TEST_SUITE=${WRKSRC}/json

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
