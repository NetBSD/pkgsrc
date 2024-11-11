# $NetBSD: Makefile,v 1.22 2024/11/11 07:29:24 wiz Exp $

DISTNAME=	httpx_socks-0.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.21.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpcore>=0.17.3:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.0.0:../../net/py-python-socks

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
