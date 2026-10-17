# $NetBSD: Makefile,v 1.23 2026/10/17 13:41:57 wiz Exp $

DISTNAME=	numpydoc-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpydoc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/numpy/numpydoc
COMMENT=	Sphinx extension to support docstrings in Numpy format
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-sphinx>=6:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib>=0:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	numpydoc

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

# as of 1.11.0
# 2 failed, 315 passed, 2 xfailed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
