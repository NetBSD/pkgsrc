# $NetBSD: Makefile,v 1.4 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	django-kronos-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-kronos/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/jgorset/django-kronos
COMMENT=	Django application to define and schedule tasks with cron
LICENSE=	mit

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-crontab>=1.9.0:../../sysutils/py-crontab
DEPENDS+=	${PYPKGPREFIX}-django>=1.7:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
