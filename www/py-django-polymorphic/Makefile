# $NetBSD: Makefile,v 1.19 2026/07/14 07:05:03 adam Exp $

DISTNAME=	django_polymorphic-4.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/jazzband/django-polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
