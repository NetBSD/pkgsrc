# $NetBSD: Makefile,v 1.23 2024/12/26 21:45:06 adam Exp $

DISTNAME=	httpx_socks-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpcore>=1.0:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.0.0:../../net/py-python-socks

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
