# $NetBSD: Makefile,v 1.1 2017/04/23 05:18:01 markd Exp $

DISTNAME=	nbconvert-5.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbconvert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org
COMMENT=	Converting Jupyter Notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pandocfilters>=1.4.1:../../textproc/py-pandocfilters
DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-mistune-[0-9]*:../../textproc/py-mistune
DEPENDS+=	${PYPKGPREFIX}-entrypoints>=0.2.2:../../devel/py-entrypoints
DEPENDS+=	${PYPKGPREFIX}-bleach-[0-9]*:../../www/py-bleach

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jupyter-nbconvert ${DESTDIR}${PREFIX}/bin/jupyter-nbconvert${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
