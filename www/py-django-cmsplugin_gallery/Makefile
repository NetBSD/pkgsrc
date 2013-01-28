# $NetBSD: Makefile,v 1.1 2013/01/28 21:16:26 adam Exp $

DISTNAME=	cmsplugin_gallery-0.5.3
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/c/cmsplugin_gallery/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails-[0-9]*:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering-[0-9]*:../../www/py-django-inline-ordering

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
