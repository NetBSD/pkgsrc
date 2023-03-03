# $NetBSD: Makefile,v 1.32 2023/03/03 09:01:36 adam Exp $

DISTNAME=	sanic-22.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sanic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sanic-org/sanic
COMMENT=	Microframework based on uvloop, httptools, and learnings of flask
LICENSE=	mit AND apache-2.0

DEPENDS+=	${PYPKGPREFIX}-aiofiles>=0.6.0:../../devel/py-aiofiles
DEPENDS+=	${PYPKGPREFIX}-httptools>=0.0.10:../../www/py-httptools
DEPENDS+=	${PYPKGPREFIX}-multidict>=5.0.0:../../databases/py-multidict
DEPENDS+=	${PYPKGPREFIX}-sanic-routing>=22.8.0:../../www/py-sanic-routing
DEPENDS+=	${PYPKGPREFIX}-ujson>=1.35:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-uvloop>=0.15.0:../../devel/py-uvloop
DEPENDS+=	${PYPKGPREFIX}-websockets>=10.0:../../www/py-websockets
TEST_DEPENDS+=	${PYPKGPREFIX}-bandit-[0-9]*:../../security/py-bandit
TEST_DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
TEST_DEPENDS+=	${PYPKGPREFIX}-black-[0-9]*:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.0:../../converters/py-chardet
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-gunicorn-[0-9]*:../../www/py-gunicorn
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=5.0.0:../../devel/py-isort
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=0.901:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
#TEST_DEPENDS+=	${PYPKGPREFIX}-sanic-testing>=22.9.0b2:../../www/py-sanic-testing
#TEST_DEPENDS+=	${PYPKGPREFIX}-slotscheck>=0.8.0:../../??/py-slotscheck
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sanic-[0-9]*:../../www/py-test-sanic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar-[0-9]*:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-types-ujson-[0-9]*:../../devel/py-types-ujson
TEST_DEPENDS+=	${PYPKGPREFIX}-uvicorn-[0-9]*:../../www/py-uvicorn

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} sanic sanic-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
