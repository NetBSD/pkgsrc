# $NetBSD: Makefile,v 1.44 2026/10/24 09:33:53 adam Exp $

DISTNAME=	asgiref-3.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/asgiref/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django/asgiref
COMMENT=	Contains various reference ASGI implementations
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0:../../devel/py-test-asyncio

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
