# $NetBSD: Makefile,v 1.3 2018/11/20 17:56:12 adam Exp $

DISTNAME=	django-filer-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filer/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer
COMMENT=	File management application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails>=2.0:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-mptt>=0.6:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic>=0.7:../../www/py-django-polymorphic

USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/filer/static/.DS_Store

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
