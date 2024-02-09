# $NetBSD: Makefile,v 1.7 2024/02/09 14:21:30 adam Exp $

DISTNAME=	widgetsnbextension-4.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/widgetsnbextension/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging-[0-9]*:../../devel/py-jupyter_packaging

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
