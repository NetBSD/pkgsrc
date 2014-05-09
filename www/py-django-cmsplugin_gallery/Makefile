# $NetBSD: Makefile,v 1.4 2014/05/09 07:37:24 wiz Exp $

DISTNAME=	cmsplugin_gallery-0.5.5
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

#PYTHON_VERSIONS_INCOMPATIBLE=   33 34 # py-django-appmedia via py-django-cms, py-django-easy-thumbnails

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
