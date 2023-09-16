# $NetBSD: Makefile,v 1.16 2023/09/16 03:16:36 adam Exp $

DISTNAME=	httpx-socks-0.7.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.21.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-httpcore>=0.17.3:../../www/py-httpcore
DEPENDS+=	${PYPKGPREFIX}-python-socks>=2.0.0:../../net/py-python-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
