# $NetBSD: Makefile,v 1.60 2023/10/28 19:57:22 wiz Exp $

DISTNAME=	aiohttp-3.9.0b0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/b/beta/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aiohttp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/aiohttp
COMMENT=	Async http client/server framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async-timeout>=4.0.0:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-aiosignal>=1.1.2:../../devel/py-aiosignal
DEPENDS+=	${PYPKGPREFIX}-attrs>=17.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=2.0:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-frozenlist>=1.1.1:../../devel/py-frozenlist
DEPENDS+=	${PYPKGPREFIX}-multidict>=4.5<7.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-yarl>=1.0<2.0:../../www/py-yarl
TEST_DEPENDS+=	${PYPKGPREFIX}-async_generator-[0-9]*:../../devel/py-async_generator
TEST_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
