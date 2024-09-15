# $NetBSD: Makefile,v 1.18 2024/09/15 07:14:02 adam Exp $

DISTNAME=	django_filer-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filer/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer
COMMENT=	File management application for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic>=2.0:../../www/py-django-polymorphic
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails>=2.0:../../www/py-easy-thumbnails

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
