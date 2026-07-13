# $NetBSD: Makefile,v 1.34 2026/07/13 08:30:57 adam Exp $

DISTNAME=	websockets-16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# even after 'make install', testing doesn't work at all
# 9 errors

PY_RENAME_BINARIES=	websockets

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
