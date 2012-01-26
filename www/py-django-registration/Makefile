# $NetBSD: Makefile,v 1.2 2012/01/26 12:49:25 obache Exp $
#

DISTNAME=	django-registration-0.8-alpha-1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S:-alpha-:a:}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://bitbucket.org/ubernostrum/django-registration/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ubernostrum/django-registration/wiki/Home
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

DEPENDS+=      ${PYPKGPREFIX}-django>=1:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

EGG_NAME=	${DISTNAME:S/-/_/g:S/registration_/registration-/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
