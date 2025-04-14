# $NetBSD: Makefile,v 1.32 2025/04/14 13:30:01 adam Exp $

DISTNAME=	daphne-4.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/daphne/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/daphne
COMMENT=	HTTP, HTTP2 and WebSocket protocol server for ASGI
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.5.2:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-autobahn>=22.4.2:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-twisted>=22.4:../../net/py-twisted
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

# test fails with:
# https://github.com/django/daphne/issues/522
# ModuleNotFoundError: No module named 'http_strategies'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} daphne daphne-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
