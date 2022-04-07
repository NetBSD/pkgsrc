# $NetBSD: Makefile,v 1.1 2022/04/07 10:19:56 adam Exp $

DISTNAME=	widgetsnbextension-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/widgetsnbextension/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	IPython HTML widgets for Jupyter
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-notebook>=4.4.1:../../www/py-notebook

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
