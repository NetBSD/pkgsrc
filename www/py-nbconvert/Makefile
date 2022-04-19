# $NetBSD: Makefile,v 1.18 2022/04/19 11:45:05 adam Exp $

DISTNAME=	nbconvert-6.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bleach>0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-defusedxml>0:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-entrypoints>=0.2.2:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.7:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyterlab-pygments>0:../../textproc/py-jupyterlab-pygments
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
DEPENDS+=	${PYPKGPREFIX}-mistune>=0.8.1:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0.5.0:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.1:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.0:../../devel/py-traitlets
# marked as extra, but required
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

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
