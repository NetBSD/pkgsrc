# $NetBSD: Makefile,v 1.7 2022/01/04 20:55:20 wiz Exp $

DISTNAME=	django-polymorphic-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/chrisglass/django_polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.1:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
