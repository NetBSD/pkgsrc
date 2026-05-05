# $NetBSD: Makefile,v 1.13 2026/05/05 08:25:56 adam Exp $

DISTNAME=	jupyter_lsp-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-lsp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-lsp/jupyterlab-lsp
COMMENT=	Multi-Language Server WebSocket proxy for Jupyter Notebook/Lab server
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.1.2:../../www/py-jupyter_server
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
