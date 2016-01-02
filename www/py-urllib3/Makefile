# $NetBSD: Makefile,v 1.4 2016/01/02 11:03:30 wiz Exp $

DISTNAME=	urllib3-1.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://urllib3.readthedocs.org/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-ndg_httpsclient-[0-9]*:../../security/py-ndg_httpsclient
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-Socks-[0-9]*:../../net/py-Socks

# actually TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-exclude-[0-9]*:../../devel/py-nose-exclude
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# four test failures as of 1.14, reported as
# https://github.com/shazow/urllib3/issues/774
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
