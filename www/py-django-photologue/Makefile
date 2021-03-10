# $NetBSD: Makefile,v 1.14 2021/03/10 19:07:06 adam Exp $

DISTNAME=	django-photologue-3.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-photologue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow>=6.0.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-sortedm2m>=3.0.0:../../www/py-django-sortedm2m
DEPENDS+=	${PYPKGPREFIX}-exifread>=2.1.2:../../graphics/py-exifread

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-django-sortedm2m

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
