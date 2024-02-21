# $NetBSD: Makefile,v 1.32 2024/02/21 11:01:37 adam Exp $

DISTNAME=	nbconvert-7.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bleach>=5.0.1:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.7:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-pygments-[0-9]*:../../textproc/py-jupyterlab-pygments
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-mistune>=2.0.3:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0.5.0:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.7:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-tinycss2-[0-9]*:../../textproc/py-tinycss2
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.1:../../devel/py-traitlets
# serve
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
TEST_DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=7.5:../../www/py-ipywidgets

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
REPLACE_PYTHON+=	nbconvert/nbconvertapp.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=3.6:../../devel/py-importlib-metadata
.endif

post-install:
.for bin in jupyter-dejavu jupyter-nbconvert
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
