# $NetBSD: Makefile,v 1.26 2026/06/04 09:47:44 prlw1 Exp $

DISTNAME=	jupyterlab-4.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyterlab/jupyterlab
COMMENT=	Next-generation user interface for Project Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.8.1:../../devel/py-hatch-jupyter-builder
DEPENDS+=	${PYPKGPREFIX}-async-lru>=1.0.0:../../devel/py-async-lru
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.25.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.5.0:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter-lsp>=2.0.0:../../www/py-jupyter-lsp
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=2.4.0:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-server>=2.28.0:../../www/py-jupyterlab-server
DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.2:../../www/py-notebook_shim
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=41.1.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets-[0-9]*:../../devel/py-traitlets

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jlpm jupyter-lab jupyter-labextension jupyter-labhub

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/jupyterlab/staging/yarn.js

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
