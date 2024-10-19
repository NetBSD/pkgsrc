# $NetBSD: Makefile,v 1.29 2024/10/19 11:16:08 wiz Exp $

DISTNAME=	sphinx_autodoc_typehints-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.25:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sphinx>=8.0.2:../../textproc/py-sphinx
# optional
DEPENDS+=	${PYPKGPREFIX}-nptyping>=2.5:../../math/py-nptyping
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.3.1:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=5:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

# bug in numpy?
# 2 warnings, 1 error

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
