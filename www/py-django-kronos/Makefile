# $NetBSD: Makefile,v 1.2 2017/04/24 16:23:50 adam Exp $

DISTNAME=	django-kronos-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-kronos/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/jgorset/django-kronos
COMMENT=	Django application to define and schedule tasks with cron
LICENSE=	mit

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-crontab-[0-9]*:../../sysutils/py-crontab
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
