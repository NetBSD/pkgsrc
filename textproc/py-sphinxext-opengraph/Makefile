# $NetBSD: Makefile,v 1.1 2026/10/24 10:48:51 adam Exp $

DISTNAME=	sphinxext_opengraph-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxext-opengraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-doc/sphinxext-opengraph
COMMENT=	Sphinx Extension to enable OGP support
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=6.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.12.3:../../www/py-beautifulsoup4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
