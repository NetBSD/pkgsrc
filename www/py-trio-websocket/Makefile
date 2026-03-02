# $NetBSD: Makefile,v 1.1 2026/03/02 20:25:53 yhardy Exp $

DISTNAME=	trio_websocket-0.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/trio_/trio-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio-websocket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/trio-websocket
COMMENT=	WebSocket library for Trio
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-trio>=0.14:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-wsproto>=0.14:../../www/py-wsproto
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
