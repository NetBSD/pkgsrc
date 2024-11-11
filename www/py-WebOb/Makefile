# $NetBSD: Makefile,v 1.20 2024/11/11 07:29:15 wiz Exp $

DISTNAME=	webob-1.8.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/webob/WebOb/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/webob/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://webob.org/
COMMENT=	Python module providing WSGI request and response objects
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/webob/WebOb/}

# as of 1.8.9
# 1 failed, 2379 passed, 9 skipped, 1 xfailed, 34 warnings

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} > 312
DEPENDS+=	${PYPKGPREFIX}-legacy-cgi-[0-9]*:../../www/py-legacy-cgi
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
