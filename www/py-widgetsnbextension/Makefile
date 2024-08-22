# $NetBSD: Makefile,v 1.9 2024/08/22 12:46:39 adam Exp $

DISTNAME=	widgetsnbextension-4.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/widgetsnbextension/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging>=0.10:../../devel/py-jupyter_packaging

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
