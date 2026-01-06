# $NetBSD: Makefile,v 1.12 2026/01/06 11:18:19 wiz Exp $

DISTNAME=	sphinxcontrib_spelling-8.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-spelling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/spelling
COMMENT=	Sphinx spelling extension
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-enchant>=3.2.2nb1:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0:../../textproc/py-sphinx
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx

# FIX: ModuleNotFoundError: No module named 'tests'
pre-test:
	${TOUCH} ${WRKSRC}/tests/__init__.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
