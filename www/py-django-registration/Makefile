# $NetBSD: Makefile,v 1.9 2017/09/04 18:08:30 wiz Exp $

DISTNAME=	django-registration-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-registration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://bitbucket.org/ubernostrum/django-registration/wiki/Home
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1:../../www/py-django

USE_LANGUAGES=		# none
USE_PKGLOCALEDIR=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
