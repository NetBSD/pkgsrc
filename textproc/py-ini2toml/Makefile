# $NetBSD: Makefile,v 1.7 2024/05/15 12:45:18 adam Exp $

DISTNAME=	ini2toml-0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ini2toml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abravalheri/ini2toml
COMMENT=	Automatically conversion of .ini/.cfg files to TOML equivalents
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=59.6:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=5:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.7:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-configupdater>=3.0.1:../../devel/py-configupdater
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly-[0-9]*:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=0.4.0:../../textproc/py-tomli_w
TEST_DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.0:../../textproc/py-tomlkit
TEST_DEPENDS+=	${PYPKGPREFIX}-validate-pyproject>=0.6:../../textproc/py-validate-pyproject

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ini2toml ini2toml-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
