# $NetBSD: Makefile,v 1.8 2020/06/19 12:04:33 adam Exp $

DISTNAME=	django-filer-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filer/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer
COMMENT=	File management application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-mptt>=0.6:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic>=0.7:../../www/py-django-polymorphic
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails>=2.0:../../www/py-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-django-mptt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
