# $NetBSD: Makefile,v 1.2 2017/09/04 17:00:46 adam Exp $

DISTNAME=	WebTest-2.0.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WebTest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webtest.pythonpaste.org/
COMMENT=	Helper to test WSGI applications
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.2:../../www/py-WebOb
DEPENDS+=	${PYPKGPREFIX}-waitress>=0.8.5:../../www/py-waitress
BUILD_DEPENDS+=	${PYPKGPREFIX}-PasteDeploy-[0-9]*:../../www/py-PasteDeploy
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
BUILD_DEPENDS+=	${PYPKGPREFIX}-WSGIProxy2-[0-9]*:../../www/py-WSGIProxy2

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
