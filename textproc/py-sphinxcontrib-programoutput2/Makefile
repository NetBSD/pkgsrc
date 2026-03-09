# $NetBSD: Makefile,v 1.1 2026/03/09 03:39:26 jnemeth Exp $

DISTNAME=	sphinxcontrib-programoutput2-2.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-programoutput2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/sphinxcontrib-programoutput/
COMMENT=	Extension to include output of arbitrary commands
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

WHEEL_NAME=	sphinxcontrib_programoutput2-0.0.0

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
