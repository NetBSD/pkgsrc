# $NetBSD: Makefile,v 1.30 2026/09/02 07:33:08 adam Exp $

DISTNAME=	websocket_client-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/websocket-client/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/websocket-client/websocket-client
COMMENT=	WebSocket client module
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-websockets>=0:../../www/py-websockets

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	wsdump

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
