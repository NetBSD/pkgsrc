# $NetBSD: Makefile,v 1.24 2024/11/11 07:29:29 wiz Exp $

DISTNAME=	websockets-13.1
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
