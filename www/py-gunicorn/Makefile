# $NetBSD: Makefile,v 1.33 2026/09/02 14:40:03 adam Exp $

DISTNAME=	gunicorn-26.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-gevent>=24.10.1:../../net/py-gevent
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	gunicorn gunicornc

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
