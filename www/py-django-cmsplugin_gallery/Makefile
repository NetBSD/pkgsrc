# $NetBSD: Makefile,v 1.11 2020/02/03 08:26:17 wiz Exp $

DISTNAME=	cmsplugin_gallery-1.0.1
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmsplugin_gallery/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.2.0:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails-[0-9]*:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering>=0.1.1:../../www/py-django-inline-ordering

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
