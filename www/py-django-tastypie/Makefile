# $NetBSD: Makefile,v 1.12 2017/11/26 17:36:00 adam Exp $

DISTNAME=	django-tastypie-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-tastypie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/toastdriven/django-tastypie/
COMMENT=	Flexible and capable API layer for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-biplist-[0-9]*:../../textproc/py-biplist
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-lxml>3:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-python-mimeparse>=0.1.4:../../www/py-python-mimeparse
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONED_DEPENDENCIES+=	python-digest

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
