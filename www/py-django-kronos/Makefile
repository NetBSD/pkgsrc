# $NetBSD: Makefile,v 1.6 2023/07/13 10:03:28 wiz Exp $

DISTNAME=	django-kronos-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-kronos/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/jgorset/django-kronos
COMMENT=	Django application to define and schedule tasks with cron
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-crontab>=1.9.0:../../sysutils/py-crontab
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=		# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
