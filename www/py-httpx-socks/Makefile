# $NetBSD: Makefile,v 1.1 2021/02/12 08:19:59 adam Exp $

DISTNAME=	httpx-socks-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httpx-socks/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/romis2012/httpx-socks
COMMENT=	Proxy (HTTP, SOCKS) transports for httpx
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-httpx>=0.15.4:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-socks>=1.1.0:../../www/py-socks

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
