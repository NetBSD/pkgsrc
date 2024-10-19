# $NetBSD: Makefile,v 1.12 2024/10/19 16:37:48 adam Exp $

DISTNAME=	pytest_httpbin-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-httpbin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kevin1024/pytest-httpbin
COMMENT=	Easily test your HTTP library against a local copy of httpbin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-httpbin-[0-9]*:../../www/py-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug
# py-requests uses py-test-httpbin for testing, avoid circular reference
#TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
