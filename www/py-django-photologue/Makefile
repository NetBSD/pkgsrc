# $NetBSD: Makefile,v 1.21 2025/04/14 14:16:21 adam Exp $

DISTNAME=	django-photologue-3.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-photologue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-sortedm2m>=3.1.1:../../www/py-django-sortedm2m
DEPENDS+=	${PYPKGPREFIX}-exifread>=3:../../graphics/py-exifread

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
