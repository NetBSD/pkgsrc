# $NetBSD: Makefile,v 1.58 2026/10/28 08:12:19 adam Exp $

DISTNAME=	sphinx_autodoc_typehints-3.17.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-autodoc-typehints/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/sphinx-autodoc-typehints
COMMENT=	Type hints support for the Sphinx autodoc extension
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=25.1:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.5:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.32.4:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-sphinx>=9.1:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-annotated-doc>=0.0.5:../../textproc/py-annotated-doc
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
TEST_DEPENDS+=	${PYPKGPREFIX}-pydantic>=2:../../devel/py-pydantic
TEST_DEPENDS+=	${PYPKGPREFIX}-sphobjinv>=2.4:../../textproc/py-sphobjinv
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=5:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.8:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.16:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 315
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.16:../../devel/py-typing-extensions
.endif

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 3.10.5
# 2 failed, 658 passed, 14 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
