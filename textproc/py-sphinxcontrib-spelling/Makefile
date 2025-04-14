# $NetBSD: Makefile,v 1.9 2025/04/14 12:56:30 adam Exp $

DISTNAME=	sphinxcontrib_spelling-8.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinxcontrib-spelling/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sphinx-contrib/spelling
COMMENT=	Sphinx spelling extension
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-enchant>=3.2.2nb1:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-requests>=2.32.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-sphinx>=3.0:../../textproc/py-sphinx
TEST_DEPENDS+=	git-base-[0-9]*:../../devel/git-base
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39 310 # py-sphinx

# FIX: ModuleNotFoundError: No module named 'tests'
pre-test:
	${TOUCH} ${WRKSRC}/tests/__init__.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
