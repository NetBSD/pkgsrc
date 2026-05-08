# $NetBSD: Makefile,v 1.72 2026/05/08 11:58:35 adam Exp $

DISTNAME=	urllib3-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/urllib3/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://urllib3.readthedocs.io/
COMMENT=	HTTP library with thread-safe connection pooling
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0.4.0:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
# optional dependencies:
# "socks"; higher requirement from dev_requirements.txt
DEPENDS+=	${PYPKGPREFIX}-Socks>=1.7.1:../../net/py-Socks

# brotli, zstd
.include "options.mk"

# needs py-cryptography>=39.0.1
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography:test

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.0.4:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=1.2.2:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-httpx>=0:../../www/py-httpx
TEST_DEPENDS+=	${PYPKGPREFIX}-quart>=0:../../www/py-quart
TEST_DEPENDS+=	${PYPKGPREFIX}-quart-trio>=0:../../www/py-quart-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.1.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=6.2:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-trio>=0.26.2:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme>=0.9.0:../../security/py-trustme

# as of 2.6.0
# 43 failed, 1681 passed, 523 skipped, 2 xfailed, 51 warnings, 1 error

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
