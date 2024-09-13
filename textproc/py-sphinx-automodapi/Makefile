# $NetBSD: Makefile,v 1.10 2024/09/13 19:25:24 adam Exp $

DISTNAME=	sphinx_automodapi-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-automodapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-automodapi
COMMENT=	Sphinx extension for auto-generating API documentation for modules
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=30.3.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	38 39 # py-sphinx

# Filenames with non-ASCII characters are not portable.
post-extract:
	${RM} ${WRKSRC}/sphinx_automodapi/tests/cases/non_ascii/output/api/sphinx_automodapi.tests.example_module.nonascii.*

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
