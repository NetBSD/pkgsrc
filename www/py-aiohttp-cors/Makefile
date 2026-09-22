# $NetBSD: Makefile,v 1.6 2026/09/22 09:55:00 adam Exp $

DISTNAME=	aiohttp_cors-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp_cors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp-cors
COMMENT=	CORS support for aiohttp
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.9:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-selenium>=0:../../www/py-selenium
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pylint>=0:../../devel/py-test-pylint

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
