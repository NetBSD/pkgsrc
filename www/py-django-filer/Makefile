# $NetBSD: Makefile,v 1.25 2025/12/28 14:50:22 adam Exp $

DISTNAME=	django_filer-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filer/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer
COMMENT=	File management application for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic>=2.0:../../www/py-django-polymorphic
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails>=2.0:../../www/py-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-svglib>=1.5.1:../../graphics/py-svglib

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
