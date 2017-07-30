# $NetBSD: Makefile,v 1.10 2017/07/30 22:32:26 wiz Exp $

DISTNAME=	django-tastypie-0.13.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-tastypie/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/toastdriven/django-tastypie/
COMMENT=	Flexible and capable API layer for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-python-mimeparse>=0.1.4:../../www/py-python-mimeparse
DEPENDS+=	${PYPKGPREFIX}-django>=1.5:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-lxml>3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-biplist-[0-9]*:../../textproc/py-biplist

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
