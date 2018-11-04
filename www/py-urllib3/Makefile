# $NetBSD: Makefile,v 1.11 2018/11/04 22:13:40 adam Exp $

DISTNAME=	urllib3-1.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://urllib3.readthedocs.io/
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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
