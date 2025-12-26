# $NetBSD: Makefile,v 1.13 2025/12/26 16:47:16 adam Exp $

DISTNAME=	django_polymorphic-4.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
