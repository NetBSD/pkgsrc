# $NetBSD: Makefile,v 1.11 2018/02/27 07:40:08 adam Exp $

DISTNAME=	django-registration-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-registration/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ubernostrum/django-registration
COMMENT=	User-registration application for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-confusable_homoglyphs>=3.0:../../converters/py-confusable_homoglyphs
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
