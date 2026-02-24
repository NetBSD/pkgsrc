# $NetBSD: Makefile,v 1.43 2026/02/24 10:58:27 adam Exp $

DISTNAME=	sphinx_autodoc_typehints-3.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sphinx>=9.1:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.3.1.2:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.15:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
