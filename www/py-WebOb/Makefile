# $NetBSD: Makefile,v 1.18 2024/10/12 08:13:13 wiz Exp $

DISTNAME=	webob-1.8.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/webob/WebOb/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webob/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://webob.org/
COMMENT=	Python module providing WSGI request and response objects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
# doesn't really support Python 3.13
# https://github.com/Pylons/webob/issues/437

WHEEL_NAME=	${DISTNAME:S/webob/WebOb/}

# as of 1.8.8
# 1 failed, 2379 passed, 9 skipped, 1 xfailed, 35 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
