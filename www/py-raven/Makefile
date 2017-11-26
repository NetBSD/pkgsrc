# $NetBSD: Makefile,v 1.1 2017/11/26 17:40:05 adam Exp $

DISTNAME=	raven-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/raven/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsentry/raven-python
COMMENT=	Raven is a client for Sentry
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-flask-login-[0-9]*:../../www/py-flask-login
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-WebOb-[0-9]*:../../www/py-WebOb
BUILD_DEPENDS+=	${PYPKGPREFIX}-WebTest-[0-9]*:../../www/py-WebTest
BUILD_DEPENDS+=	${PYPKGPREFIX}-anyjson-[0-9]*:../../textproc/py-anyjson
BUILD_DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
BUILD_DEPENDS+=	${PYPKGPREFIX}-celery>=2.5:../../net/py-celery
BUILD_DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
BUILD_DEPENDS+=	${PYPKGPREFIX}-exam>=0.5.2:../../devel/py-exam
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.5.0:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-logbook-[0-9]*:../../devel/py-logbook
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
BUILD_DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=3.2.0:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-assume-[0-9]*:../../devel/py-test-assume
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0.9:../../devel/py-test-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-pythonpath>=0.7.1:../../devel/py-test-pythonpath
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-sugar>=0.8:../../devel/py-test-sugar
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.2.0:../../devel/py-test-timeout
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=1.18.2:../../devel/py-test-xdist
BUILD_DEPENDS+=	${PYPKGPREFIX}-tornado>=4.1:../../www/py-tornado
BUILD_DEPENDS+=	${PYPKGPREFIX}-zconfig-[0-9]*:../../devel/py-zconfig
# also www/py-django-tastypie?

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-contextlib2-[0-9]*:../../devel/py-contextlib2
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} raven raven${PYVERSSUFFIX} || ${TRUE}

pre-test:
	cd ${WRKSRC} && mkdir -p static # && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
