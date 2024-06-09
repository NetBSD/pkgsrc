# $NetBSD: Makefile,v 1.20 2024/06/09 14:18:58 wiz Exp $

DISTNAME=	sphinx_autodoc_typehints-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.21.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.1.2:../../textproc/py-sphinx
# optional
DEPENDS+=	${PYPKGPREFIX}-nptyping>=2.5:../../math/py-nptyping
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.3.1:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.7.1:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
