# $NetBSD: Makefile,v 1.63 2024/01/29 06:53:52 adam Exp $

DISTNAME=	aiohttp-3.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-aiosignal>=1.1.2:../../devel/py-aiosignal
DEPENDS+=	${PYPKGPREFIX}-frozenlist>=1.1.1:../../devel/py-frozenlist
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.5<7.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.0<2.0:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

# need to package: re-assert, python-on-whales, proxy (!?)
# leads to, as of 3.9.0:
# 8 failed, 2112 passed, 31 skipped, 3 deselected, 26 xfailed, 35 errors
pre-test:
	cd ${WRKSRC} && ${RM} -f tests/test_client_session.py tests/test_proxy_functional.py \
		tests/test_streams.py tests/test_urldispatch.py tests/test_web_response.py \
		tests/autobahn/test_autobahn.py

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.0:../../devel/py-async-timeout
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
