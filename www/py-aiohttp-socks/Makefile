# $NetBSD: Makefile,v 1.21 2024/07/31 09:06:19 adam Exp $

DISTNAME=	aiohttp_socks-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-socks/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/aiohttp-socks
COMMENT=	SOCKS proxy connector for aiohttp
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.10.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.4.3:../../net/py-python-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
