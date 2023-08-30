# $NetBSD: Makefile,v 1.9 2023/08/30 14:36:56 adam Exp $

DISTNAME=	django-polymorphic-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/chrisglass/django_polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
