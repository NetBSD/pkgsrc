# $NetBSD: Makefile,v 1.35 2023/04/24 07:18:56 adam Exp $

DISTNAME=	httplib2-0.22.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/httplib2/}

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	https://github.com/httplib2/httplib2
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.4:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-cryptography>=38.0.3:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.9.2:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-future>=0.18.3:../../devel/py-future
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.5:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.12.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-forked>=1.3.0:../../devel/py-test-forked
TEST_DEPENDS+=	${PYPKGPREFIX}-test-randomly>=1.2.3:../../devel/py-test-randomly
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.4.2:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.34.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
