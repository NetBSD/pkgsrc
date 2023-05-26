# $NetBSD: Makefile,v 1.11 2023/05/26 19:42:01 adam Exp $

DISTNAME=	pytest-httpbin-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
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

PYTHON_VERSIONS_INCOMPATIBLE=	27

# This is not enough; package needs to be installed for testing
#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
