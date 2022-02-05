# $NetBSD: Makefile,v 1.23 2022/02/05 12:03:44 adam Exp $

DISTNAME=	notebook-6.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Web-based notebook environment for interactive computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Send2Trash>=1.8.0:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-argon2-cffi>0:../../security/py-argon2-cffi
DEPENDS+=	${PYPKGPREFIX}-ipykernel>0:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils>0:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=5.3.4:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.6.1:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jinja2>0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-nbconvert>0:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat>0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio>=1.5:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-prometheus_client>0:../../net/py-prometheus_client
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.3:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.0.0:../../net/py-zmq

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes
PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

post-install:
.for name in bundlerextension nbextension notebook serverextension
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-${name} jupyter-${name}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
