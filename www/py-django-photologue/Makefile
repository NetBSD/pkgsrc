# $NetBSD: Makefile,v 1.22 2025/09/03 14:45:26 adam Exp $

DISTNAME=	django-photologue-3.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-photologue/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=10:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-django-sortedm2m>=4.0.0:../../www/py-django-sortedm2m
DEPENDS+=	${PYPKGPREFIX}-exifread>=3:../../graphics/py-exifread

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
