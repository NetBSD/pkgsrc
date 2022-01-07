# $NetBSD: Makefile,v 1.33 2022/01/07 16:18:59 adam Exp $

DISTNAME=	urllib3-1.26.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://urllib3.readthedocs.io/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.14:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-Socks>=1.6.0:../../net/py-Socks
DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.3.4:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-ipaddress-[0-9]*:../../net/py-ipaddress
.endif

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
