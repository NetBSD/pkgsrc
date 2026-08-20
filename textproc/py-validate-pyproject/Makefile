# $NetBSD: Makefile,v 1.22 2026/08/20 05:26:09 adam Exp $

DISTNAME=	validate_pyproject-0.26
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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly-[0-9]*:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	validate-pyproject

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
