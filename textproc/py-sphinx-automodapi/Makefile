# $NetBSD: Makefile,v 1.18 2025/12/22 08:46:07 adam Exp $

DISTNAME=	sphinx_automodapi-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-automodapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-automodapi
COMMENT=	Sphinx extension for auto-generating API documentation for modules
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.0.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 # py-sphinx

# Filenames with non-ASCII characters are not portable.
post-extract:
	${RM} ${WRKSRC}/sphinx_automodapi/tests/cases/non_ascii/output/api/sphinx_automodapi.tests.example_module.nonascii.*

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
