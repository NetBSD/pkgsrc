# $NetBSD: Makefile,v 1.2 2023/08/01 23:20:55 wiz Exp $

DISTNAME=	nbclassic-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbclassic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/nbclassic
COMMENT=	Jupyter Notebook as a Jupyter Server extension
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Send2Trash>=1.8.0:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi-[0-9]*:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=6.1.1:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.1:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.8:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-nbconvert>=5:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio>=1.5:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.2.3:../../www/py-notebook_shim
DEPENDS+=	${PYPKGPREFIX}-prometheus_client-[0-9]*:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.3:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.0.0:../../net/py-zmq

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
.for bin in jupyter-nbclassic jupyter-nbclassic-bundlerextension \
		jupyter-nbclassic-extension jupyter-nbclassic-serverextension
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
