# $NetBSD: Makefile,v 1.9 2026/09/12 19:56:43 wiz Exp $

DISTNAME=	jupyterlab_widgets-3.0.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-widgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-widgets/ipywidgets
COMMENT=	Jupyter interactive widgets for JupyterLab
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-jupyter-builder>=0:../../devel/py-hatch-jupyter-builder
DEPENDS+=	${PYPKGPREFIX}-jupyter-builder>=1.0:../../devel/py-jupyter-builder

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
