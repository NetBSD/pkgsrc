# $NetBSD: Makefile,v 1.13 2024/05/10 11:16:02 adam Exp $

DISTNAME=	flask_caching-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=F/Flask-Caching/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sh4nks/flask-caching
COMMENT=	Caching support to your Flask application
LICENSE=	modified-bsd

WHEEL_NAME=	Flask_Caching-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cachelib>=0.9.0:../../devel/py-cachelib
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-asgiref-[0-9]*:../../www/py-asgiref
TEST_DEPENDS+=	${PYPKGPREFIX}-libmc-[0-9]*:../../devel/py-libmc
TEST_DEPENDS+=	${PYPKGPREFIX}-redis-[0-9]*:../../databases/py-redis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xprocess-[0-9]*:../../devel/py-test-xprocess

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
