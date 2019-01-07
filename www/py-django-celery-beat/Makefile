# $NetBSD: Makefile,v 1.3 2019/01/07 12:59:35 adam Exp $

DISTNAME=	django-celery-beat-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_celery_beat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/django-celery-beat
COMMENT=	Database-backed Periodic Tasks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-celery>=4.0:../../net/py-celery
DEPENDS+=	${PYPKGPREFIX}-django-timezone-field>=2.0:../../www/py-django-timezone-field
DEPENDS+=	${PYPKGPREFIX}-crontab>=2.3.4:../../sysutils/py-crontab

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
