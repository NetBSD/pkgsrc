# $NetBSD: Makefile,v 1.1 2025/12/05 20:59:57 wiz Exp $

DISTNAME=	hypercorn-0.18.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hypercorn/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pgjones/hypercorn
COMMENT=	ASGI and WSGI Server based on Hyper libraries
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-h11-[0-9]*:../../www/py-h11
DEPENDS+=	${PYPKGPREFIX}-h2>=4.3.0:../../www/py-h2
DEPENDS+=	${PYPKGPREFIX}-priority-[0-9]*:../../www/py-priority
DEPENDS+=	${PYPKGPREFIX}-wsproto>=0.14.0:../../www/py-wsproto
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx-[0-9]*:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-trio-[0-9]*:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-trio-[0-9]*:../../devel/py-test-trio

USE_LANGUAGES=	# none

# as of 0.18.0
# 2 failed, 194 passed

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
