# $NetBSD: Makefile,v 1.44 2023/01/12 08:10:24 adam Exp $

DISTNAME=	urllib3-1.26.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://urllib3.readthedocs.io/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-Socks>=1.7.1:../../net/py-Socks
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=38.0.3:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky>=3.7.0:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.5:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.4:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-freezegun>=0.4.2:../../devel/py-test-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.4.2:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1.0:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.7.0:../../security/py-trustme

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
