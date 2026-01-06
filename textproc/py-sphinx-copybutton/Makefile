# $NetBSD: Makefile,v 1.9 2026/01/06 11:18:18 wiz Exp $

DISTNAME=	sphinx-copybutton-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-copybutton/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/executablebooks/sphinx-copybutton
COMMENT=	Sphinx module to add a copy button to code cells
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
