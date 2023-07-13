# $NetBSD: Makefile,v 1.11 2023/07/13 10:03:27 wiz Exp $

DISTNAME=	django-filer-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-filer/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-filer
COMMENT=	File management application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.04:../../textproc/py-Unidecode
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-mptt>=0.6:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-polymorphic>=2.0:../../www/py-django-polymorphic
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails>=2.0:../../www/py-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
