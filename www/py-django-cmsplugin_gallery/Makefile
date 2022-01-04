# $NetBSD: Makefile,v 1.13 2022/01/04 20:55:18 wiz Exp $

DISTNAME=	cmsplugin_gallery-1.1.7
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmsplugin_gallery/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.2.0:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-filer>=1.2.4:../../www/py-django-filer
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering>=0.1.1:../../www/py-django-inline-ordering
DEPENDS+=	${PYPKGPREFIX}-easy-thumbnails-[0-9]*:../../www/py-easy-thumbnails

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
