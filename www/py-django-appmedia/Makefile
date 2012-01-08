# $NetBSD: Makefile,v 1.2 2012/01/08 07:51:20 adam Exp $

DISTNAME=	django-appmedia-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-appmedia/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/django-appmedia
COMMENT=	Handling django app media
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=		${DISTNAME:S/-/_/}
USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
