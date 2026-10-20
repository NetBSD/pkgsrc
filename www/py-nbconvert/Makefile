# $NetBSD: Makefile,v 1.45 2026/10/20 06:16:24 adam Exp $

DISTNAME=	nbconvert-7.17.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bleach>=5.0.1:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.7:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-pygments>=0:../../textproc/py-jupyterlab-pygments
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-mistune>=2.0.3:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0.5.0:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.7:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1:../../devel/py-traitlets
# serve
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel>=0:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=7.5:../../www/py-ipywidgets

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jupyter-dejavu jupyter-nbconvert
PYTHON_SELF_CONFLICT=	yes
REPLACE_PYTHON+=	nbconvert/nbconvertapp.py

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
