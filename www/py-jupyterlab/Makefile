# $NetBSD: Makefile,v 1.5 2023/10/28 19:57:24 wiz Exp $

DISTNAME=	jupyterlab-4.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/jupyterlab/
COMMENT=	Next-generation user interface for Project Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.3.2:../../devel/py-hatch-jupyter-builder
DEPENDS+=	${PYPKGPREFIX}-async-lru>=1.0.0:../../devel/py-async-lru
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter-lsp>=2.0.0:../../www/py-jupyter-lsp
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=2.4.0:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-server>=2.19.0:../../www/py-jupyterlab-server
DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.2:../../www/py-notebook_shim
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets-[0-9]*:../../devel/py-traitlets

USE_LANGUAGES=	# none

CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/jupyterlab/staging/yarn.js

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=4.8.3:../../devel/py-importlib-metadata
.endif
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

post-install:
.for bin in jlpm jupyter-lab jupyter-labextension jupyter-labhub
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
