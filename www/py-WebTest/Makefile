# $NetBSD: Makefile,v 1.14 2025/02/05 13:29:01 adam Exp $

DISTNAME=	webtest-3.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/webt/WebT/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebTest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webtest.pythonpaste.org/
COMMENT=	Helper to test WSGI applications
LICENSE=	mit

WHEEL_NAME=	${DISTNAME:S/webt/WebT/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.2:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-waitress>=0.8.5:../../www/py-waitress
TEST_DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
TEST_DEPENDS+=	${PYPKGPREFIX}-WSGIProxy2-[0-9]*:../../www/py-WSGIProxy2
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
