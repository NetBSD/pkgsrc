# $NetBSD: Makefile,v 1.11 2025/11/03 12:17:39 adam Exp $

DISTNAME=	django_polymorphic-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django_polymorphic/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/chrisglass/django_polymorphic
COMMENT=	Simplifies using inherited models in Django projects
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
