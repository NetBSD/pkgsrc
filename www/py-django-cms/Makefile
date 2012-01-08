# $NetBSD: Makefile,v 1.7 2012/01/08 07:56:58 adam Exp $

DISTNAME=	django-cms-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-cms/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.django-cms.org/
COMMENT=	Django content management system
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	27 26 25

EGG_NAME=		${DISTNAME:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-imaging-[0-9]*:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-django-south-[0-9]*:../../www/py-django-south
DEPENDS+=	${PYPKGPREFIX}-django-classy-tags-[0-9]*:../../www/py-django-classy-tags
DEPENDS+=	${PYPKGPREFIX}-django-appmedia-[0-9]*:../../www/py-django-appmedia
DEPENDS+=	${PYPKGPREFIX}-django-mptt-[0-9]*:../../www/py-django-mptt
DEPENDS+=	${PYPKGPREFIX}-django-sekizai-[0-9]*:../../www/py-django-sekizai

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
