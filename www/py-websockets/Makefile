# $NetBSD: Makefile,v 1.30 2025/02/18 10:32:28 adam Exp $

DISTNAME=	websockets-15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# even after 'make install', testing doesn't work at all
# 9 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
