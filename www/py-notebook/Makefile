# $NetBSD: Makefile,v 1.20 2021/12/30 13:05:41 adam Exp $

DISTNAME=	notebook-6.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Web-based notebook environment for interactive computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Send2Trash-[0-9]*:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=5.3.1:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.4.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-nbconvert-[0-9]*:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-prometheus_client-[0-9]*:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.1:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=5:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.0.0:../../net/py-zmq

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-ipykernel

post-install:
.for name in bundlerextension nbextension notebook serverextension
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-${name} jupyter-${name}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
