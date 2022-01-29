# $NetBSD: Makefile,v 1.14 2022/01/29 08:48:41 wiz Exp $

DISTNAME=	raven-6.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/raven/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsentry/raven-python
COMMENT=	Client for Sentry
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-blinker>=1.1:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
TEST_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest
TEST_DEPENDS+=	${PYPKGPREFIX}-aiohttp-[0-9]*:../../www/py-aiohttp
TEST_DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
TEST_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
TEST_DEPENDS+=	${PYPKGPREFIX}-celery>=2.5:../../net/py-celery
TEST_DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
TEST_DEPENDS+=	${PYPKGPREFIX}-exam>=0.5.2:../../devel/py-exam
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-login>=0.2.0:../../www/py-flask-login
TEST_DEPENDS+=	${PYPKGPREFIX}-logbook-[0-9]*:../../devel/py-logbook
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
# avoid circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-sanic>=0.7.0:../../www/py-sanic
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.5.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=1.0.0:../../devel/py-test-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pythonpath>=0.7.1:../../devel/py-test-pythonpath
TEST_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.8:../../devel/py-test-sugar
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.2.1:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.18.2:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-tornado>=4.1:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-zconfig-[0-9]*:../../devel/py-zconfig

PYTHON_VERSIONED_DEPENDENCIES+=	test:test
PYTHON_VERSIONED_DEPENDENCIES+=	flake8:test

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == py27
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
TEST_DEPENDS=	# none; py-aiohttp and py-sanic are incompatible with py27
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2-[0-9]*:../../devel/py-unittest2
do-test:
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} raven raven-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
