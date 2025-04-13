# $NetBSD: Makefile,v 1.5 2025/04/13 08:19:14 adam Exp $

DISTNAME=	jupyterlab_widgets-3.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-widgets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter-widgets/ipywidgets
COMMENT=	Jupyter interactive widgets for JupyterLab
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging>=0.10:../../devel/py-jupyter_packaging

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
