# $NetBSD: Makefile,v 1.4 2022/01/11 09:13:29 adam Exp $

DISTNAME=	black-21.12b0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/black/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://black.readthedocs.io/
COMMENT=	Uncompromising Python code formatter
LICENSE=	mit

USE_LANGUAGES=	# none

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-mypy_extensions>=0.4.3:../../lang/py-mypy_extensions
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.9.0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-tomli>=0.2.6:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0.2:../../devel/py-typing-extensions
# only for blackd:
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.7.4:../../www/py-aiohttp

PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typed-ast>=1.4.0:../../devel/py-typed-ast
.endif

USE_PKG_RESOURCES=	yes

post-install:
.for bin in black black-primer blackd
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
