# $NetBSD: Makefile,v 1.5 2021/07/22 13:36:42 adam Exp $

DISTNAME=	django-celery-beat-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_celery_beat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/django-celery-beat
COMMENT=	Database-backed Periodic Tasks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-celery>=4.4:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2
DEPENDS+=	${PYPKGPREFIX}-django-timezone-field>=4.1.0:../../www/py-django-timezone-field
DEPENDS+=	${PYPKGPREFIX}-crontab>=2.3.4:../../sysutils/py-crontab

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
