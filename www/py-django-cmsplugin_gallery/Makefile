# $NetBSD: Makefile,v 1.8 2018/03/13 08:17:14 wen Exp $

DISTNAME=	cmsplugin_gallery-1.0.0
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cmsplugin_gallery/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/cmsplugin_gallery
COMMENT=	DjangoCMS image gallery plugin
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-django-easy-thumbnails-[0-9]*:../../www/py-django-easy-thumbnails
DEPENDS+=	${PYPKGPREFIX}-django-inline-ordering-[0-9]*:../../www/py-django-inline-ordering

USE_LANGUAGES=		# none

post-patch:
	${MV} ${WRKSRC}/tests ${WRKSRC}/cmsplugin_gallery/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
