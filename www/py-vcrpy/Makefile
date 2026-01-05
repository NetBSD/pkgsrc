# $NetBSD: Makefile,v 1.8 2026/01/05 16:08:27 adam Exp $

DISTNAME=	vcrpy-8.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_PYPI:=v/vcrpy/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/kevin1024/vcrpy
COMMENT=	VCR.py simplifies and speeds up tests that make HTTP requests
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wrapt>0:../../devel/py-wrapt
DEPENDS+=	${PYPKGPREFIX}-yaml>0:../../textproc/py-yaml
# Not mentioned in dependencies:
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.0:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-yarl>0:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-test-aiohttp>0:../../www/py-test-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=1.0.0:../../www/py-test-httpbin

PYTHON_VERSIONS_INCOMPATIBLE=	310

# as of 6.0.1
# 60 failed, 173 passed, 9 skipped, 14 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
