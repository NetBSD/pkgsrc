# $NetBSD: Makefile,v 1.1 2022/01/17 09:25:22 wiz Exp $

DISTNAME=	sphinx-automodapi-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-automodapi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astropy/sphinx-automodapi
COMMENT=	Sphinx extension for auto-generating API documentation for modules
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-sphinx>=2.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	sphinx_automodapi-0.0.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
