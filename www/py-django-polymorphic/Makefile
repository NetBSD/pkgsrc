# $NetBSD: Makefile,v 1.5 2020/06/19 11:55:27 adam Exp $

DISTNAME=	django-polymorphic-2.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/chrisglass/django_polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
