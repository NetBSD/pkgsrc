# $NetBSD: Makefile,v 1.6 2025/05/17 07:47:29 adam Exp $

DISTNAME=	jupyterlab_widgets-3.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-widgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-widgets/ipywidgets
COMMENT=	Jupyter interactive widgets for JupyterLab
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0.8.1:../../devel/py-hatch-jupyter-builder

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
