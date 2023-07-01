# $NetBSD: Makefile,v 1.10 2023/07/01 11:31:53 wiz Exp $

DISTNAME=	sphinx_autodoc_typehints-1.23.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5.3:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.3.1:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.2:../../devel/py-test
TOOL_DEPENDS+=	${PYPKGPREFIX}-nptyping-[0-9]*:../../math/py-nptyping
#TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

# needs 'make install'
do-test:
	cd ${WRKSRC} && ${MAKE_ENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
