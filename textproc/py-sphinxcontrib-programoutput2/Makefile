# $NetBSD: Makefile,v 1.5 2026/10/16 19:44:22 adam Exp $

DISTNAME=	sphinxcontrib-programoutput2-2.0a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-programoutput2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/sphinxcontrib-programoutput/
COMMENT=	Extension to include output of arbitrary commands
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

WHEEL_NAME=	sphinxcontrib_programoutput2-2.0a1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
