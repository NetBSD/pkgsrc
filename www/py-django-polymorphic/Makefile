# $NetBSD: Makefile,v 1.1 2016/04/20 20:01:14 adam Exp $

DISTNAME=	django_polymorphic-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django_polymorphic/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/chrisglass/django_polymorphic/
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
