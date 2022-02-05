# $NetBSD: Makefile,v 1.13 2022/02/05 11:29:16 adam Exp $

DISTNAME=	nbconvert-6.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-bleach>0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-defusedxml>0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-entrypoints>=0.2.2:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.4:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-pygments>0:../../textproc/py-jupyterlab-pygments
DEPENDS+=	${PYPKGPREFIX}-mistune>=0.8.1:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0.5.0:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=4.4:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.0:../../devel/py-traitlets
# marked as extra, but required
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in jupyter-dejavu jupyter-nbconvert
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
