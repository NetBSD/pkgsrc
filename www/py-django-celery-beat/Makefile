# $NetBSD: Makefile,v 1.11 2024/10/14 07:48:33 wiz Exp $

DISTNAME=	django_celery_beat-2.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_celery_beat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/django-celery-beat
COMMENT=	Database-backed Periodic Tasks
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.8.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-celery>=5.2.3:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-timezone-field>=5.0:../../www/py-django-timezone-field
DEPENDS+=	${PYPKGPREFIX}-cron-descriptor>=1.2.32:../../sysutils/py-cron-descriptor
DEPENDS+=	${PYPKGPREFIX}-crontab>=2.3.4:../../sysutils/py-crontab
DEPENDS+=	${PYPKGPREFIX}-tzdata-[0-9]*:../../time/py-tzdata
TEST_DEPENDS+=	${PYPKGPREFIX}-ephem-[0-9]*:../../math/py-ephem
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

# as of 2.7.0
# 2 failed, 104 passed, 9 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
