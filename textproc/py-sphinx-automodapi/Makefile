# $NetBSD: Makefile,v 1.3 2023/05/05 18:16:08 adam Exp $

DISTNAME=	sphinx-automodapi-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-automodapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-automodapi
COMMENT=	Sphinx extension for auto-generating API documentation for modules
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0:../../textproc/py-sphinx
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
