# $NetBSD: Makefile,v 1.23 2026/10/26 05:42:46 adam Exp $

DISTNAME=	validate_pyproject-0.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/validate-pyproject/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abravalheri/validate-pyproject
COMMENT=	Validation library and CLI tool for checking on pyproject.toml files
LICENSE=	mpl-2.0 AND mit AND modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-fastjsonschema>=2.16.2:../../textproc/py-fastjsonschema
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	validate-pyproject

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
