# $NetBSD: Makefile,v 1.18 2025/12/27 21:02:04 adam Exp $

DISTNAME=	webtest-3.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/webt/WebT/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebTest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webtest.pythonpaste.org/
COMMENT=	Helper to test WSGI applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.2:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-waitress>=3.0.2:../../www/py-waitress
TEST_DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
TEST_DEPENDS+=	${PYPKGPREFIX}-WSGIProxy2-[0-9]*:../../www/py-WSGIProxy2
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
