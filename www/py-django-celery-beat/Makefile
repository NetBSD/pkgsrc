# $NetBSD: Makefile,v 1.2 2018/02/22 10:30:38 adam Exp $

DISTNAME=	django-celery-beat-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_celery_beat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/django-celery-beat
COMMENT=	Database-backed Periodic Tasks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-celery>=4.0:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-ephem>=3.7.6.0:../../math/py-ephem
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-case>=1.3.1:../../devel/py-case
BUILD_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=3.0:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
