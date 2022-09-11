# $NetBSD: Makefile,v 1.40 2022/09/11 17:14:22 wiz Exp $

DISTNAME=	urllib3-1.26.12
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
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

PYTHON_VERSIONS_INCOMPATIBLE=	27

PYSETUPTESTTARGET=	pytest

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
