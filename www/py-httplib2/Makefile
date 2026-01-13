# $NetBSD: Makefile,v 1.40 2026/01/13 12:35:39 adam Exp $

DISTNAME=	httplib2-0.31.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.4:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=45:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.9.2:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-forked>=1.6.0:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=3.12.0:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.3.1:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.5.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 0.31.0
# 1 failed, 467 passed, 6 skipped, 1 xfailed, 1 xpassed, 16 warnings

# needs unpackaged socks package
pre-test:
	${RM} ${WRKSRC}/tests/test_proxy.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
