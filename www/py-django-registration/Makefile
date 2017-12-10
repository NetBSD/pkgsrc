# $NetBSD: Makefile,v 1.10 2017/12/10 16:36:31 adam Exp $

DISTNAME=	django-registration-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-registration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://bitbucket.org/ubernostrum/django-registration/wiki/Home
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-confusable_homoglyphs>=2.0:../../converters/py-confusable_homoglyphs
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=		# none
USE_PKGLOCALEDIR=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
