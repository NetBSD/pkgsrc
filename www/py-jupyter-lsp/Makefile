# $NetBSD: Makefile,v 1.1 2023/09/01 05:17:02 adam Exp $

DISTNAME=	jupyter-lsp-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-lsp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-lsp/jupyterlab-lsp
COMMENT=	Multi-Language Server WebSocket proxy for Jupyter Notebook/Lab server
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.1.2:../../www/py-jupyter_server
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.8.3:../../devel/py-importlib-metadata
.endif

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
