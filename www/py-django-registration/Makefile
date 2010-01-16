# $NetBSD: Makefile,v 1.1.1.1 2010/01/16 10:53:26 abs Exp $
#

DISTNAME=	django-registration-0.8-alpha-1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S:-alpha-:a:}
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

PYDISTUTILSPKG=	# yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
