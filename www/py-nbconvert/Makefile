# $NetBSD: Makefile,v 1.11 2021/12/30 13:05:41 adam Exp $

DISTNAME=	nbconvert-5.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-bleach-[0-9]*:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-entrypoints>=0.2.2:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipywidgets>=7:../../www/py-ipywidgets
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.4:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=5.3.1:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-mistune>=0.8.1:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbformat>=4.4:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-ipykernel

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-nbconvert jupyter-nbconvert-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
