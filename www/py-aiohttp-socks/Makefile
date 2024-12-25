# $NetBSD: Makefile,v 1.24 2024/12/25 10:02:36 adam Exp $

DISTNAME=	aiohttp_socks-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp-socks/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/aiohttp-socks
COMMENT=	SOCKS proxy connector for aiohttp
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.10.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.4.3:../../net/py-python-socks

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
