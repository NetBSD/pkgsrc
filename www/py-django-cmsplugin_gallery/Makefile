# $NetBSD: Makefile,v 1.16 2025/04/14 13:30:02 adam Exp $

DISTNAME=	cmsplugin_gallery-2.0.3
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmsplugin_gallery/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.9.0:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.2.4:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering>=1.0.2:../../www/py-django-inline-ordering
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails-[0-9]*:../../www/py-easy-thumbnails

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
