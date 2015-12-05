# $NetBSD: Makefile,v 1.6 2015/12/05 21:26:05 adam Exp $

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

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

EGG_NAME=	${DISTNAME:S/-/_/g:S/registration_/registration-/}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.8a1

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
