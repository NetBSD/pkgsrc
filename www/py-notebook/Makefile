# $NetBSD: Makefile,v 1.8 2018/05/11 19:46:36 minskim Exp $

DISTNAME=	notebook-5.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org/
COMMENT=	Web-based notebook environment for interactive computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Send2Trash-[0-9]*:../../sysutils/py-Send2Trash
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=5.2.0:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=4.4.0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-nbconvert-[0-9]*:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.1:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-tornado>=4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-zmq>=17.0.0:../../net/py-zmq

USE_LANGUAGES=	# none

post-install:
	for f in jupyter-bundlerextension jupyter-nbextension jupyter-notebook jupyter-serverextension; do \
		${MV} ${DESTDIR}${PREFIX}/bin/$$f ${DESTDIR}${PREFIX}/bin/$${f}${PYVERSSUFFIX} || ${TRUE}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
