# $NetBSD: Makefile,v 1.2 2023/05/03 08:49:17 wiz Exp $

DISTNAME=	jupyterlab_pygments-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyterlab-pygments/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Pygments theme using JupyterLab CSS variables
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pygments>=2.4.1:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
