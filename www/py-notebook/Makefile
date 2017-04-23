# $NetBSD: Makefile,v 1.1 2017/04/23 05:23:27 markd Exp $

DISTNAME=	notebook-5.0.0rc2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=n/notebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org
COMMENT=	web-based notebook environment for interactive computing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-terminado>=0.3.3:../../www/py-terminado
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2.1:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-tornado>=4:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-nbformat-[0-9]*:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-nbconvert-[0-9]*:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-jupyter_core-[0-9]*:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-jupyter_client-[0-9]*:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

REPLACE_INTERPRETER+=	node
REPLACE.node.old=	.*node[^ ]*
REPLACE.node.new=	${PREFIX}/bin/node
REPLACE_FILES.node=	scripts/less-watch

USE_LANGUAGES=	# none

post-install:
	for f in jupyter-bundlerextension jupyter-nbextension jupyter-notebook jupyter-serverextension less-watch; do \
		${MV} ${DESTDIR}${PREFIX}/bin/$$f ${DESTDIR}${PREFIX}/bin/$${f}${PYVERSSUFFIX} || ${TRUE}; \
	done

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
