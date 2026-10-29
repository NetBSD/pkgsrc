# $NetBSD: Makefile,v 1.12 2026/10/29 13:32:22 adam Exp $

DISTNAME=	sphinxcontrib_httpdomain-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-httpdomain/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/httpdomain
COMMENT=	Sphinx domain for documenting HTTP APIs
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.12.22:../../devel/py-uv-build
DEPENDS+=	${PYPKGPREFIX}-sphinx>=8.1.3:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
