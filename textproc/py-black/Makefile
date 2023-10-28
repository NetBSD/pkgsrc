# $NetBSD: Makefile,v 1.20 2023/10/28 20:09:12 wiz Exp $

DISTNAME=	black-23.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/black/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://black.readthedocs.io/
COMMENT=	Uncompromising Python code formatter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.8.0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.9.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
# only needed for blackd:
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.4:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.1:../../devel/py-typing-extensions
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
