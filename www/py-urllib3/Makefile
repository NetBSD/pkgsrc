# $NetBSD: Makefile,v 1.60 2024/05/10 10:44:25 wiz Exp $

DISTNAME=	urllib3-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://urllib3.readthedocs.io/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.6.0:../../devel/py-hatchling
# optional dependencies:
# "socks"; higher requirement from dev_requirements.txt
DEPENDS+=	${PYPKGPREFIX}-Socks>=1.7.1:../../net/py-Socks
# "secure"
#PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL cryptography
#DEPENDS+=	${PYPKGPREFIX}-idna>=2.0.0:../../www/py-idna
#DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../www/py-certify
# but also needs unpackaged urlib3-secure-extra

PYTHON_VERSIONS_INCOMPATIBLE=	27

# brotli, zstd
.include "options.mk"

# needs py-cryptography>=39.0.1
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography:test

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.0.4:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.2.2:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-towncrier>=21.9.0:../../wip/py-towncrier
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.9.0:../../security/py-trustme
#hypercorn @ git+https://github.com/urllib3/hypercorn@urllib3-changes
#pytest-memray==1.5.0; sys_platform!="win32" and implementation_name=="cpython"

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 309
TEST_DEPENDS+=	${PYPKGPREFIX}-backports.zoneinfo>=0.2.1:../../time/py-backports.zoneinfo
.endif

# as of 2.1.0 with the missing dependencies above
# 36 failed, 1501 passed, 507 skipped, 108 warnings

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
