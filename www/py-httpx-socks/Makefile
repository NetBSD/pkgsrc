# $NetBSD: Makefile,v 1.6 2021/10/26 17:27:29 adam Exp $

DISTNAME=	httpx-socks-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.20.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpcore>=0.13.7:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-python-socks>=1.2.4:../../net/py-python-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36 # py-httpcore, py-anyio, py-uvloop

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
