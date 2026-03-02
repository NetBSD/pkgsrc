# $NetBSD: Makefile,v 1.2 2026/03/02 20:37:19 wiz Exp $

DISTNAME=	trio_websocket-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/trio_/trio-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio-websocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/trio-websocket
COMMENT=	WebSocket library for Trio
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-trio>=0.14:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-wsproto>=0.14:../../www/py-wsproto
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# as of 0.12.2
# 8 failed, 2 passed, 2 warnings, 54 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
