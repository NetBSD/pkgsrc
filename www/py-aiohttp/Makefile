# $NetBSD: Makefile,v 1.106 2026/06/02 05:11:04 adam Exp $

DISTNAME=	aiohttp-3.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-pkgconfig>=0:../../devel/py-pkgconfig
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-aiohappyeyeballs>=2.5.0:../../net/py-aiohappyeyeballs
DEPENDS+=	${PYPKGPREFIX}-aiosignal>=1.4.0:../../devel/py-aiosignal
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-frozenlist>=1.1.1:../../devel/py-frozenlist
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.5:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-propcache>=0.2.0:../../devel/py-propcache
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.17.0:../../www/py-yarl
# speedups
DEPENDS+=	${PYPKGPREFIX}-aiodns>=3.3.0:../../net/py-aiodns
TEST_DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
TEST_DEPENDS+=	${PYPKGPREFIX}-re-assert-[0-9]*:../../devel/py-re-assert
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
#TEST_DEPENDS+=	${PYPKGPREFIX}-isal-[0-9]*:../../wip/py-isal
TEST_DEPENDS+=	${PYPKGPREFIX}-zlib-ng-[0-9]*:../../archivers/py-zlib-ng
#TEST_DEPENDS+=	${PYPKGPREFIX}-blockbuster-[0-9]*:../../wip/py-blockbuster

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
# need to package: proxy (!?)
# as of 3.13.4
# 8 failed, 3711 passed, 77 skipped, 8 xfailed, 42 errors, 2 subtests passed
pre-test:
	cd ${WRKSRC} && ${RM} -f tests/test_proxy_functional.py tests/autobahn/test_autobahn.py

.include "../../mk/bsd.pkg.mk"
