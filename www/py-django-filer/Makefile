# $NetBSD: Makefile,v 1.1 2016/04/20 20:09:32 adam Exp $

DISTNAME=	django-filer-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-filer/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer/
COMMENT=	File management application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails-[0-9]*:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-mptt-[0-9]*:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic-[0-9]*:../../www/py-django-polymorphic

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
