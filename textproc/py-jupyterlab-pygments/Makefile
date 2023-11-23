# $NetBSD: Makefile,v 1.4 2023/11/23 21:00:30 adam Exp $

DISTNAME=	jupyterlab_pygments-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyterlab/jupyterlab_pygments
COMMENT=	Pygments theme using JupyterLab CSS variables
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.5:../../devel/py-hatch-jupyter-builder
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-nodejs-version>=0.3.2:../../devel/py-hatch-nodejs-version
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5.0:../../devel/py-hatchling

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
