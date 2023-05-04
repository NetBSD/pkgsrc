# $NetBSD: Makefile,v 1.3 2023/05/04 19:18:23 adam Exp $

DISTNAME=	jupyterlab_pygments-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Pygments theme using JupyterLab CSS variables
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging>=0.10:../../devel/py-jupyter_packaging
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
