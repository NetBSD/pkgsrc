# $NetBSD: Makefile,v 1.6 2017/05/10 17:12:16 adam Exp $

DISTNAME=	urllib3-1.21.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://urllib3.readthedocs.io/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-Socks-[0-9]*:../../net/py-Socks
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.endif

# actually TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-exclude-[0-9]*:../../devel/py-nose-exclude
BUILD_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

# four test failures as of 1.14, reported as
# https://github.com/shazow/urllib3/issues/774
#do-test:
#	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
