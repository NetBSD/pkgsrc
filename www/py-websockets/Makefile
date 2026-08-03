# $NetBSD: Makefile,v 1.37 2026/08/03 17:58:08 wiz Exp $

DISTNAME=	websockets-17.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websockets/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aaugustin/websockets
COMMENT=	Implementation of the WebSocket Protocol (RFC 6455)
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

# test suite is only intended for developers
# https://websockets.readthedocs.io/en/stable/project/contributing.html#packaging

PY_RENAME_BINARIES=	websockets

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
