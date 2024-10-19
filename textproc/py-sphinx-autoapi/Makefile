# $NetBSD: Makefile,v 1.20 2024/10/19 11:14:17 wiz Exp $

DISTNAME=	sphinx_autoapi-3.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx_autoapi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/readthedocs/sphinx-autoapi
COMMENT=	Autodoc style documentation for multiple languages
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-anyascii-[0-9]*:../../textproc/py-anyascii
DEPENDS+=	${PYPKGPREFIX}-astroid>=2.7:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-sphinx>=5.2.0:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

TEST_ENV+=		PYTHONPATH=${WRKSRC}/build/lib
# as of 3.3.2
# 317 passed, 2 errors
# all pass with
ALLOW_NETWORK_ACCESS=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
