# $NetBSD: Makefile,v 1.40 2026/03/09 12:48:24 adam Exp $

DISTNAME=	black-26.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/black/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://black.readthedocs.io/
COMMENT=	Uncompromising Python code formatter
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme-[0-9]*:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.3.0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=1.0.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pytokens>=0.4.0:../../devel/py-pytokens
# only needed for blackd:
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.10:../../www/py-aiohttp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in black blackd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
