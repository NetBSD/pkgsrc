# $NetBSD: Makefile,v 1.12 2026/10/16 19:44:21 adam Exp $

DISTNAME=	sphinxcontrib-jquery-4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-jquery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/jquery
COMMENT=	Extension to include jQuery on newer Sphinx releases
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=4:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
