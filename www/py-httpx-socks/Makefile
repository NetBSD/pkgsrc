# $NetBSD: Makefile,v 1.26 2025/12/11 10:04:52 adam Exp $

DISTNAME=	httpx_socks-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-httpcore>=1.0:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.28.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.4.3:../../net/py-python-socks
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.1.0:../../misc/py-sniffio
TEST_DEPENDS+=	${PYPKGPREFIX}-hypercorn>0:../../www/py-hypercorn
TEST_DEPENDS+=	${PYPKGPREFIX}-starlette>0:../../www/py-starlette

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
