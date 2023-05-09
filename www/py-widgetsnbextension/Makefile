# $NetBSD: Makefile,v 1.4 2023/05/09 17:05:16 wiz Exp $

DISTNAME=	widgetsnbextension-4.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/widgetsnbextension/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jupyter.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-jupyter_packaging-[0-9]*:../../devel/py-jupyter_packaging

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
