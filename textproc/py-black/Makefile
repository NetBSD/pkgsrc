# $NetBSD: Makefile,v 1.6 2022/01/31 09:55:42 wiz Exp $

DISTNAME=	black-22.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/black/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://black.readthedocs.io/
COMMENT=	Uncompromising Python code formatter
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-click>=8.0.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.9.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomli>=1.1.0:../../textproc/py-tomli
# only needed for blackd:
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.4:../../www/py-aiohttp

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.4.2:../../devel/py-typed-ast
.endif
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.0:../../devel/py-typing-extensions
.endif

USE_PKG_RESOURCES=	yes

post-install:
.for bin in black black-primer blackd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
