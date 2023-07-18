# $NetBSD: Makefile,v 1.5 2023/07/18 04:39:14 adam Exp $

DISTNAME=	widgetsnbextension-4.0.8
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

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
