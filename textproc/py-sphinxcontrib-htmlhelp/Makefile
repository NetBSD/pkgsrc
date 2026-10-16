# $NetBSD: Makefile,v 1.19 2026/10/16 19:44:21 adam Exp $

DISTNAME=	sphinxcontrib_htmlhelp-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-htmlhelp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sphinx-doc.org/
COMMENT=	Sphinx API for HTML help
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=5:../../textproc/py-sphinx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
