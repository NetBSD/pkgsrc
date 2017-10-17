# $NetBSD: Makefile,v 1.2 2017/10/17 18:31:40 adam Exp $

DISTNAME=	nbconvert-5.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-bleach-[0-9]*:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-entrypoints>=0.2.2:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=4.2:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-mistune>=0.7.4:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-nbformat>=4.4:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets
BUILD_DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} jupyter-nbconvert jupyter-nbconvert${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
