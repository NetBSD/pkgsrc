# $NetBSD: Makefile,v 1.12 2026/11/11 22:45:48 wiz Exp $

DISTNAME=	hishel-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hishel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/karpetrosyan/hishel
COMMENT=	Persistent cache implementation for httpx and httpcore
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-msgpack>=1.1.2:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.1:../../devel/py-typing-extensions
# optional, install them for testing
TEST_DEPENDS+=	${PYPKGPREFIX}-anysqlite>=0:../../databases/py-anysqlite
TEST_DEPENDS+=	${PYPKGPREFIX}-fakeredis>=0:../../databases/py-fakeredis
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx2>=0:../../www/py-httpx2
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=0:../../time/py-time-machine
TEST_DEPENDS+=	${PYPKGPREFIX}-fastapi>=0:../../www/py-fastapi

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

# as of 2.0.0
# 973 passed, 208 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
