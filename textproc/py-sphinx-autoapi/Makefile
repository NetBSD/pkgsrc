# $NetBSD: Makefile,v 1.29 2026/01/06 11:18:17 wiz Exp $

DISTNAME=	sphinx_autoapi-3.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_autoapi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/readthedocs/sphinx-autoapi
COMMENT=	Autodoc style documentation for multiple languages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-astroid>=3.0.0:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.4.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

# as of 3.6.1
# 316 passed, 3636 warnings, 4 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
