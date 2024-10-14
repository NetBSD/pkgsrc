# $NetBSD: Makefile,v 1.74 2024/10/14 16:56:43 adam Exp $

DISTNAME=	aiohttp-3.10.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=46.4.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-aiohappyeyeballs>=2.3.0:../../net/py-aiohappyeyeballs
DEPENDS+=	${PYPKGPREFIX}-aiosignal>=1.1.2:../../devel/py-aiosignal
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-frozenlist>=1.1.1:../../devel/py-frozenlist
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.5:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.12.0:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
TEST_DEPENDS+=	${PYPKGPREFIX}-re-assert-[0-9]*:../../devel/py-re-assert
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.0:../../devel/py-async-timeout
.endif

.include "../../lang/python/wheel.mk"
# need to package: proxy (!?)
# leads to, as of 3.10.9:
# 4 failed, 3204 passed, 30 skipped, 6 deselected, 25 xfailed, 37 errors
pre-test:
	cd ${WRKSRC} && ${RM} -f tests/test_proxy_functional.py tests/autobahn/test_autobahn.py

.include "../../mk/bsd.pkg.mk"
