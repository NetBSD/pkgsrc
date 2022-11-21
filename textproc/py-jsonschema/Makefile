# $NetBSD: Makefile,v 1.30 2022/11/21 20:06:08 adam Exp $

DISTNAME=	jsonschema-4.17.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Julian/jsonschema
COMMENT=	Implementation of JSON Schema for Python
LICENSE=	modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
BUILD_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
BUILD_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.4.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-pyrsistent>=0.17.3:../../devel/py-pyrsistent
TEST_DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 39
DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=1.4.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-pkgutil_resolve_name>=1.3.10:../../devel/py-pkgutil_resolve_name
.endif

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jsonschema jsonschema-${PYVERSSUFFIX} || ${TRUE}

TEST_ENV+=	JSON_SCHEMA_TEST_SUITE=${WRKSRC}/json

# after 'make install'
do-test:
	cd ${WRKSRC}/jsonschema && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
