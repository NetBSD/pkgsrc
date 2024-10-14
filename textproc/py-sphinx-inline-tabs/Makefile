# $NetBSD: Makefile,v 1.7 2024/10/14 06:46:02 wiz Exp $

DISTNAME=	sphinx_inline_tabs-2023.4.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-inline-tabs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pradyunsg/sphinx-inline-tabs
COMMENT=	Sphinx module to add inline tabbed content
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
