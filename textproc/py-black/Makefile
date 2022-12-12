# $NetBSD: Makefile,v 1.12 2022/12/12 10:07:36 adam Exp $

DISTNAME=	black-22.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/black/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://black.readthedocs.io/
COMMENT=	Uncompromising Python code formatter
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.8.0:../../devel/py-hatchling
BUILD_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
BUILD_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.9.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
# only needed for blackd:
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.4:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.0:../../devel/py-typing-extensions
.endif

post-install:
.for bin in black blackd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
