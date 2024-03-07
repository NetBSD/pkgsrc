# $NetBSD: Makefile,v 1.20 2024/03/07 16:49:22 adam Exp $

DISTNAME=	httpx-socks-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.21.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpcore>=0.17.3:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.0.0:../../net/py-python-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
