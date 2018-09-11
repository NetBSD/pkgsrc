# $NetBSD: Makefile,v 1.15 2018/09/11 07:51:47 adam Exp $

DISTNAME=	django-tastypie-0.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-tastypie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/toastdriven/django-tastypie
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
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
