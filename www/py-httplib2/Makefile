# $NetBSD: Makefile,v 1.39 2025/09/21 15:54:22 wiz Exp $

DISTNAME=	httplib2-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.4:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=38.0.3:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.9.2:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-future>=0.18.3:../../devel/py-future
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.12.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-forked>=1.3.0:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=1.2.3:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.4.2:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist

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
