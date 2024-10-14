# $NetBSD: Makefile,v 1.5 2024/10/14 08:13:15 wiz Exp $

DISTNAME=	nbclassic-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbclassic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/nbclassic
COMMENT=	Jupyter Notebook as a Jupyter Server extension
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging>=0.9:../../devel/py-jupyter_packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=1.17.0:../../www/py-jupyter_server
DEPENDS+=	${PYPKGPREFIX}-ipykernel-[0-9]*:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-ipython_genutils-[0-9]*:../../devel/py-ipython_genutils
DEPENDS+=	${PYPKGPREFIX}-nest-asyncio>=1.5:../../devel/py-nest-asyncio
DEPENDS+=	${PYPKGPREFIX}-notebook_shim>=0.2.3:../../www/py-notebook_shim

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

# https://github.com/jupyter/nbclassic/issues/308
PYTHON_VERSIONS_INCOMPATIBLE=	39 313

post-install:
.for bin in jupyter-nbclassic jupyter-nbclassic-bundlerextension \
		jupyter-nbclassic-extension jupyter-nbclassic-serverextension
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
