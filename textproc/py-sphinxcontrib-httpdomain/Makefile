# $NetBSD: Makefile,v 1.11 2026/10/16 19:44:21 adam Exp $

DISTNAME=	sphinxcontrib_httpdomain-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-httpdomain/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/httpdomain
COMMENT=	Sphinx domain for documenting HTTP APIs
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-sphinx>=6.0:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
